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

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsOneIfOnlyLeftNeighborIsAlive)
{
    grid[1][0] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsTwoIfLeftAndRightNeighborsAlive)
{
    grid[1][0] = ALIVE;
    grid[1][2] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 2);
}
TEST_F(neighbors, returnsOneIfOnlyTopNeighborIsAlive)
{
    grid[0][1] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}
TEST_F(neighbors, returnsOneIfOnlyBottomNeighborIsAlive)
{
    grid[2][1] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsOneIfOnlyTopLeftNeighborIsAlive)
{
    grid[0][0] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsOneIfOnlyTopRightNeighborIsAlive)
{
    grid[0][2] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsOneIfOnlyBottomLeftNeighborIsAlive)
{
    grid[2][0] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighbors, returnsOneIfOnlyBottomRightNeighborIsAlive)
{
    grid[2][2] = ALIVE;

    EXPECT_EQ(countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

// can use GTEST_SKIP(); in test function

TEST_F(neighbors, givesZeroAliveNeighborsForCellOnLeftEdge)
{
    // Make everything alive
    memset(grid, ALIVE, sizeof(grid));

    EXPECT_EQ(countAliveNeighbors(0, 5), 0);
}

TEST_F(neighbors, givesZeroAliveNeighborsForCellOnRightEdge)
{
    // Make everything alive
    memset(grid, ALIVE, sizeof(grid));

    EXPECT_EQ(countAliveNeighbors(NUM_COLS - 1, 5), 0);
}

TEST_F(neighbors, givesZeroAliveNeighborsForCellOnTopEdge)
{
    // Make everything alive
    memset(grid, ALIVE, sizeof(grid));

    EXPECT_EQ(countAliveNeighbors(5, 0), 0);
}

TEST_F(neighbors, givesZeroAliveNeighborsForCellOnBottomEdge)
{
    // Make everything alive
    memset(grid, ALIVE, sizeof(grid));

    EXPECT_EQ(countAliveNeighbors(5, NUM_ROWS - 1), 0);
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

TEST_F(neighbors, canApplyRules)
{

    IGNORE();

    gameSetup();

    // bool *g = *grid;
    // bool *a = *altGrid;

    // bool expectedGrid[NUM_COLS][NUM_ROWS];
    // bool *e = *expectedGrid;
    // memset(expectedGrid, DEAD, sizeof(expectedGrid)); // All Dead
    // int index = 22 * NUM_COLS + 22;
    // *(e + index) = ALIVE;

    // computeGeneration(e, g);

    EXPECT_EQ(grid[22][22], ALIVE);
}
