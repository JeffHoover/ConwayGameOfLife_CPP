#include "Arduino.h"
#include <gtest/gtest.h>
#include "life.h"

#define TEST_CELL_ROW 1
#define TEST_CELL_COL 1

using namespace ::testing;

class neighbors : public ::testing::Test
{
protected:
    void SetUp() override
    {
        mockInit();
    }
};

TEST_F(neighbors, returnsOneIfOnlyRightNeighborIsAlive)
{

    memset(grid, false, sizeof(grid));
    grid[1][2] = true;

    EXPECT_EQ(countNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsOneIfOnlyLeftNeighborIsAlive)
{

    memset(grid, false, sizeof(grid));
    grid[1][0] = true;

    EXPECT_EQ(countNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsTwoIfLeftAndRightNeighborsAlive)
{

    memset(grid, false, sizeof(grid));
    grid[1][0] = true;
    grid[1][2] = true;

    EXPECT_EQ(countNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 2);
}
TEST_F(neighbors, returnsOneIfOnlyTopNeighborIsAlive)
{

    memset(grid, false, sizeof(grid));
    grid[0][1] = true;

    EXPECT_EQ(countNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}
TEST_F(neighbors, returnsOneIfOnlyBottomNeighborIsAlive)
{

    memset(grid, false, sizeof(grid));
    grid[2][1] = true;

    EXPECT_EQ(countNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsOneIfOnlyTopLeftNeighborIsAlive)
{

    memset(grid, false, sizeof(grid));
    grid[0][0] = true;

    EXPECT_EQ(countNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsOneIfOnlyTopRightNeighborIsAlive)
{

    memset(grid, false, sizeof(grid));
    grid[0][2] = true;

    EXPECT_EQ(countNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsOneIfOnlyBottomLeftNeighborIsAlive)
{

    memset(grid, false, sizeof(grid));
    grid[2][0] = true;

    EXPECT_EQ(countNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

