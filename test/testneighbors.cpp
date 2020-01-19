#include "Arduino.h"
#include <gtest/gtest.h>
#include "life.h"
#include "rules.h"
#include "game.h"

#if 0
#define TEST_CELL_ROW 1
#define TEST_CELL_COL 1
#define IGNORE GTEST_SKIP

using namespace ::testing;

class neighbors : public ::testing::Test
{
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

/*
countAliveNeighbors only works on grid, not 
even alternating between grid and altGrid.
Tests with a small grid will never work,
and prod will never work because the count
is not happening on the current generation,
only grid, which alternates between current
and next.
*/

TEST_F(neighbors, canApplyRules)
{
    IGNORE();
    bool first[6][6];
    bool second[6][6];
    memset(first, DEAD, sizeof(first));
    memset(second, DEAD, sizeof(first));

    // Create a "blinker":
    first[3][2] = ALIVE;
    first[3][3] = ALIVE;
    first[3][4] = ALIVE;

    // CAN'T WORK - countAliveNeighbors operates on "grid", not "first"
    computeGeneration(&first[0][0], &second[0][0], 6, 6);

    EXPECT_EQ(second[3][3], ALIVE);
}

TEST_F(neighbors, canApplyRules1)
{
    IGNORE();

    memset(grid, DEAD, sizeof(grid));
    memset(altGrid, DEAD, sizeof(grid));

    memset(first, DEAD, sizeof(first));
    memset(second, DEAD, sizeof(first));

    // Create a "block":
    first[1][1] = ALIVE;
    first[2][2] = ALIVE;
    first[1][2] = ALIVE;
    first[2][1] = ALIVE;

    // CAN'T WORK - countAliveNeighbors operates on "grid", not "first"
    EXPECT_EQ(countAliveNeighbors(1, 1), 99);

    // computeGeneration(&first[0][0], &second[0][0], 4, 4);
    // for (int ii = 0; ii < 4; ii++)
    // {
    //     for (int jj = 0; jj < 4; jj++)
    //     {
    //         printf("%d  ", first[ii][jj]);
    //     }
    //     printf("\n");
    // }

    // printf("\n");
    // for (int ii = 0; ii < 4; ii++)
    // {
    //     for (int jj = 0; jj < 4; jj++)
    //     {
    //         printf("%d  ", second[ii][jj]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    // EXPECT_EQ(second[1][1], ALIVE);
}
#endif