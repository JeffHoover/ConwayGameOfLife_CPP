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

        // Start with everything dead
        memset(grid, false, sizeof(grid));
    }
};

TEST_F(neighbors, returnsOneIfOnlyRightNeighborIsAlive)
{
    grid[1][2] = true;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsOneIfOnlyLeftNeighborIsAlive)
{
    grid[1][0] = true;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsTwoIfLeftAndRightNeighborsAlive)
{
    grid[1][0] = true;
    grid[1][2] = true;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 2);
}
TEST_F(neighbors, returnsOneIfOnlyTopNeighborIsAlive)
{
    grid[0][1] = true;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}
TEST_F(neighbors, returnsOneIfOnlyBottomNeighborIsAlive)
{
    grid[2][1] = true;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsOneIfOnlyTopLeftNeighborIsAlive)
{
    grid[0][0] = true;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsOneIfOnlyTopRightNeighborIsAlive)
{
    grid[0][2] = true;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsOneIfOnlyBottomLeftNeighborIsAlive)
{
    grid[2][0] = true;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsOneIfOnlyBottomRightNeighborIsAlive)
{
    grid[2][2] = true;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

// can use GTEST_SKIP(); in test function

TEST_F(neighbors, givesZeroAliveNeighborsForCellOnLeftEdge)
{
    // Make everything alive
    memset(grid, true, sizeof(grid));

    EXPECT_EQ(countAliveNeighbors(0, TEST_CELL_COL), 0);
}

TEST_F(neighbors, givesZeroAliveNeighborsForCellOnRightEdge)
{
    // Make everything alive
    memset(grid, true, sizeof(grid));

    EXPECT_EQ(countAliveNeighbors(NUM_ROWS, TEST_CELL_COL), 0);
}

TEST_F(neighbors, givesZeroAliveNeighborsForCellOnTopEdge)
{
    // Make everything alive
    memset(grid, true, sizeof(grid));

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, 0), 0);
}

TEST_F(neighbors, givesZeroAliveNeighborsForCellOnBottomEdge)
{
    // Make everything alive
    memset(grid, true, sizeof(grid));

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, NUM_COLS), 0);
}

// This isn't the right test.
TEST_F(neighbors, canApplyRules)
{

    gameSetup();
    computeGeneration(&grid, &altGrid);

    EXPECT_EQ(memcmp(grid, altGrid, sizeof(grid)), 0);
}