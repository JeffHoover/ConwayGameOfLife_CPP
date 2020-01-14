#include "Arduino.h"
#include <gtest/gtest.h>
#include "life.h"

using namespace ::testing;

class neighbors : public ::testing::Test {
 protected:
  void SetUp() override {
     mockInit();
  }
};

TEST_F(neighbors, liveCellWithFewerThanTwoLiveNeighborsDies) {
    bool cellIsAlive = true;
    int neighborCount = 1;

    EXPECT_EQ(applyRules(cellIsAlive, neighborCount), false);
}
TEST_F(neighbors, liveCellWithTwoLiveNeighborsLives) {
    bool cellIsAlive = true;
    int neighborCount = 2;

    EXPECT_EQ(applyRules(cellIsAlive, neighborCount), true);
}
TEST_F(neighbors, liveCellWithTrheeLiveNeighborsLives) {
    bool cellIsAlive = true;
    int neighborCount = 3;

    EXPECT_EQ(applyRules(cellIsAlive, neighborCount), true);
}
TEST_F(neighbors, liveCellWithMoreThanThreeLiveNeighborsDies) {
    bool cellIsAlive = true;
    int neighborCount = 4;

    EXPECT_EQ(applyRules(cellIsAlive, neighborCount), false);
}
TEST_F(neighbors, deadCellWithThreeNeighborsComesToLife) {
    bool cellIsAlive = false;
    int neighborCount = 3;

    EXPECT_EQ(applyRules(cellIsAlive, neighborCount), true);

}
TEST_F(neighbors, deadCellWithTwoNeighborsStaysDead) {
    bool cellIsAlive = false;
    int neighborCount = 2;

    EXPECT_EQ(applyRules(cellIsAlive, neighborCount), false);

}
TEST_F(neighbors, returnsOneIfOnlyRightNeighborIsAlive) {

    memset(grid, false, sizeof(grid));
    grid[1][2] = true;

    int row = 1;
    int col = 1;

    EXPECT_EQ(countNeighbors(row, col), 1);

}

TEST_F(neighbors, returnsOneIfOnlyLeftNeighborIsAlive) {

    memset(grid, false, sizeof(grid));
    grid[1][0] = true;

    int row = 1;
    int col = 1;

    EXPECT_EQ(countNeighbors(row, col), 1);

}

TEST_F(neighbors, returnsTwoIfLeftAndRightNeighborsAlive) {

    memset(grid, false, sizeof(grid));
    grid[1][0] = true;
    grid[1][2] = true;

    int row = 1;
    int col = 1;

    EXPECT_EQ(countNeighbors(row, col), 2);

}
TEST_F(neighbors, returnsOneIfOnlyTopNeighborIsAlive) {

    memset(grid, false, sizeof(grid));
    grid[0][1] = true;

    int row = 1;
    int col = 1;

    EXPECT_EQ(countNeighbors(row, col), 1);

}
TEST_F(neighbors, returnsOneIfOnlyBottomNeighborIsAlive) {

    memset(grid, false, sizeof(grid));
    grid[2][1] = true;

    int row = 1;
    int col = 1;

    EXPECT_EQ(countNeighbors(row, col), 1);

}

TEST_F(neighbors, returnsOneIfOnlyTopLeftNeighborIsAlive) {

    memset(grid, false, sizeof(grid));
    grid[0][0] = true;

    int row = 1;
    int col = 1;

    EXPECT_EQ(countNeighbors(row, col), 1);

}

TEST_F(neighbors, returnsOneIfOnlyTopRightNeighborIsAlive) {

    memset(grid, false, sizeof(grid));
    grid[0][2] = true;

    int row = 1;
    int col = 1;

    EXPECT_EQ(countNeighbors(row, col), 1);

}

TEST_F(neighbors, returnsOneIfOnlyBottomLeftNeighborIsAlive) {

    memset(grid, false, sizeof(grid));
    grid[2][0] = true;

    int row = 1;
    int col = 1;

    EXPECT_EQ(countNeighbors(row, col), 1);

}

// TEST_F(display, setsRightNumberOfPixels) {

//     grid[1][1] = true;
//     grid[2][2] = true;
//     grid[3][3] = true;
//     grid[14][4] = true;
//     grid[5][5] = true;

//     testMatrix.display(grid);

//     EXPECT_EQ(testMatrix.getPixelAssignmentCount(), 5);
// }