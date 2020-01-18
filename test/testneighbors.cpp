#include "Arduino.h"
#include <gtest/gtest.h>
#include "life.h"

#define TEST_CELL_ROW 1
#define TEST_CELL_COL 1
#define IGNORE GTEST_SKIP

using namespace ::testing;

class neighbors : public ::testing::Test
{
protected:
    void SetUp() override
    {
        mockInit();

        // Start with everything dead
        memset(grid, DEAD, sizeof(grid));
    }
};

TEST_F(neighbors, returnsOneIfOnlyRightNeighborIsAlive)
{
    grid[1][2] = ALIVE;
    printf("z ");
    bool *arg3 = *grid;
    printf("z ");
    fflush(stdout);
    int numLive = countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL, arg3);
    printf("z ");
    printf("\n");
    fflush(stdout);
    EXPECT_EQ(numLive, 1);
}
/*
TEST_F(neighbors, returnsOneIfOnlyLeftNeighborIsAlive)
{
    grid[1][0] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL, *grid), 1);
}

TEST_F(neighbors, returnsTwoIfLeftAndRightNeighborsAlive)
{
    grid[1][0] = ALIVE;
    grid[1][2] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL, *grid), 2);
}
TEST_F(neighbors, returnsOneIfOnlyTopNeighborIsAlive)
{
    grid[0][1] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL, *grid), 1);
}
TEST_F(neighbors, returnsOneIfOnlyBottomNeighborIsAlive)
{
    grid[2][1] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL, *grid), 1);
}

TEST_F(neighbors, returnsOneIfOnlyTopLeftNeighborIsAlive)
{
    grid[0][0] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL, *grid), 1);
}

TEST_F(neighbors, returnsOneIfOnlyTopRightNeighborIsAlive)
{
    grid[0][2] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL, *grid), 1);
}

TEST_F(neighbors, returnsOneIfOnlyBottomLeftNeighborIsAlive)
{
    grid[2][0] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL, *grid), 1);
}

TEST_F(neighbors, returnsOneIfOnlyBottomRightNeighborIsAlive)
{
    grid[2][2] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL, *grid), 1);
}

// can use GTEST_SKIP(); in test function

TEST_F(neighbors, givesZeroAliveNeighborsForCellOnLeftEdge)
{
    // Make everything alive
    memset(grid, ALIVE, sizeof(grid));

    EXPECT_EQ(countAliveNeighbors(0, 5, *grid), 0);
}

TEST_F(neighbors, givesZeroAliveNeighborsForCellOnRightEdge)
{
    // Make everything alive
    memset(grid, ALIVE, sizeof(grid));

    EXPECT_EQ(countAliveNeighbors(NUM_COLS - 1, 5, *grid), 0);
}

TEST_F(neighbors, givesZeroAliveNeighborsForCellOnTopEdge)
{
    // Make everything alive
    memset(grid, ALIVE, sizeof(grid));

    EXPECT_EQ(countAliveNeighbors(5, 0, *grid), 0);
}

TEST_F(neighbors, givesZeroAliveNeighborsForCellOnBottomEdge)
{
    // Make everything alive
    memset(grid, ALIVE, sizeof(grid));

    EXPECT_EQ(countAliveNeighbors(5, NUM_ROWS - 1, *grid), 0);
}

void setRemoteVal(bool *, bool);
void setRemoteVal(bool *addr, bool val)
{
    *addr = val;
}
TEST_F(neighbors, canChangeValueAtPointer)
{
    bool localVal = DEAD;
    setRemoteVal(&localVal, ALIVE);

    EXPECT_EQ(localVal, ALIVE);
}
*/
TEST_F(neighbors, canApplyRules)
{

    gameSetup();

    grid[3][3] = ALIVE;

    // bool *g = *grid;
    // bool *a = *altGrid;

    // bool expectedGrid[NUM_COLS][NUM_ROWS];
    // bool *e = *expectedGrid;
    // memset(expectedGrid, DEAD, sizeof(expectedGrid)); // All Dead
    // int index = 22 * NUM_COLS + 22;
    // *(e + index) = ALIVE;

    computeGeneration(*grid, *altGrid);

    EXPECT_EQ(altGrid[3][3], DEAD);
    EXPECT_EQ(altGrid[3][3], DEAD);
}

TEST_F(neighbors, canApplyRules2)
{

    gameSetup();

    grid[3][3] = ALIVE;
    grid[4][3] = ALIVE;
    grid[3][4] = ALIVE;
    grid[4][4] = ALIVE;

    grid[30][28] = ALIVE;

    computeGeneration(*grid, *altGrid);

    EXPECT_EQ(altGrid[30][28], DEAD);

    EXPECT_EQ(altGrid[3][3], ALIVE);
    EXPECT_EQ(altGrid[4][3], ALIVE);
    EXPECT_EQ(altGrid[3][4], ALIVE);
    EXPECT_EQ(altGrid[4][4], ALIVE);
}