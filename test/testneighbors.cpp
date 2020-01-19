#include "Arduino.h"
#include <gtest/gtest.h>
#include "board.h"
#include "rules.h"
#include "game.h"

#define IGNORE GTEST_SKIP

using namespace ::testing;

class neighborsTest : public ::testing::Test
{
public:
    Board board;

    void SetUp() override
    {
        board.kill();
    }
};

#define TEST_CELL_ROW 2
#define TEST_CELL_COL 2

TEST_F(neighborsTest, returnsOneIfOnlyRightNeighborIsAlive)
{
    board.set(TEST_CELL_ROW + 1, TEST_CELL_COL, ALIVE);
    EXPECT_EQ(board.countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighborsTest, returnsOneIfOnlyLeftNeighborIsAlive)
{
    board.set(TEST_CELL_ROW - 1, TEST_CELL_COL, ALIVE);
    EXPECT_EQ(board.countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighborsTest, returnsTwoIfLeftAndRightNeighborsAlive)
{
    board.set(TEST_CELL_ROW + 1, TEST_CELL_COL, ALIVE);
    board.set(TEST_CELL_ROW - 1, TEST_CELL_COL, ALIVE);
    EXPECT_EQ(board.countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 2);
}

TEST_F(neighborsTest, returnsOneIfOnlyTopNeighborIsAlive)
{
    board.set(TEST_CELL_ROW, TEST_CELL_COL + 1, ALIVE);
    EXPECT_EQ(board.countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighborsTest, returnsOneIfOnlyBottomNeighborIsAlive)
{
    board.set(TEST_CELL_ROW, TEST_CELL_COL - 1, ALIVE);
    EXPECT_EQ(board.countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighborsTest, returnsOneIfOnlyTopLeftNeighborIsAlive)
{
    board.set(TEST_CELL_ROW - 1, TEST_CELL_COL - 1, ALIVE);
    EXPECT_EQ(board.countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighborsTest, returnsOneIfOnlyTopRightNeighborIsAlive)
{
    board.set(TEST_CELL_ROW + 1, TEST_CELL_COL - 1, ALIVE);
    EXPECT_EQ(board.countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighborsTest, returnsOneIfOnlyBottomRightNeighborIsAlive)
{
    IGNORE();

    EXPECT_EQ(board.countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighborsTest, returnsOneIfOnlyBottomLeftNeighborIsAlive)
{
    IGNORE();

    EXPECT_EQ(board.countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighborsTest, givesZeroAliveNeighborsForCellOnLeftEdge)
{
    IGNORE();

    // Make everything alive

    EXPECT_EQ(board.countAliveNeighbors(0, 5), 0);
}

TEST_F(neighborsTest, givesZeroAliveNeighborsForCellOnRightEdge)
{
    IGNORE();

    // Make everything alive

    EXPECT_EQ(board.countAliveNeighbors(NUM_COLS - 1, 5), 0);
}

TEST_F(neighborsTest, givesZeroAliveNeighborsForCellOnTopEdge)
{
    IGNORE();

    // Make everything alive

    EXPECT_EQ(board.countAliveNeighbors(5, 0), 0);
}

TEST_F(neighborsTest, givesZeroAliveNeighborsForCellOnBottomEdge)
{
    IGNORE();

    // Make everything alive

    EXPECT_EQ(board.countAliveNeighbors(5, NUM_ROWS - 1), 0);
}

TEST_F(neighborsTest, canApplyRules)
{
    IGNORE();

    // Create a "blinker":
    // first[3][2] = ALIVE;
    // first[3][3] = ALIVE;
    // first[3][4] = ALIVE;

    //computeGeneration(&first[0][0], &second[0][0], 6, 6);

    EXPECT_EQ(board.get(3, 3), ALIVE);
}

TEST_F(neighborsTest, canApplyRules1)
{
    IGNORE();

    // Create a "block":
    // first[1][1] = ALIVE;
    // first[2][2] = ALIVE;
    // first[1][2] = ALIVE;
    // first[2][1] = ALIVE;

    EXPECT_EQ(board.countAliveNeighbors(1, 1), 99);
}
