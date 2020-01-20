#include "Arduino.h"
#include <gtest/gtest.h>
#include "game.h"
#include "board.h"
#include "rules.h"

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
    board.set(TEST_CELL_ROW + 1, TEST_CELL_COL + 1, ALIVE);

    EXPECT_EQ(board.countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighborsTest, returnsOneIfOnlyBottomLeftNeighborIsAlive)
{
    board.set(TEST_CELL_ROW - 1, TEST_CELL_COL + 1, ALIVE);

    EXPECT_EQ(board.countAliveNeighbors(TEST_CELL_ROW, TEST_CELL_COL), 1);
}

TEST_F(neighborsTest, givesFiveAliveNeighborsForCellOnLeftEdge)
{
    board.set(0, 4, ALIVE);
    board.set(0, 6, ALIVE);

    board.set(1, 4, ALIVE);
    board.set(1, 5, ALIVE);
    board.set(1, 6, ALIVE);

    EXPECT_EQ(board.countAliveNeighbors(0, 5), 5);
}

TEST_F(neighborsTest, gives5AliveNeighborsForCellOnTopEdge)
{
    board.set(4, 0, ALIVE);
    board.set(6, 0, ALIVE);

    board.set(4, 1, ALIVE);
    board.set(5, 1, ALIVE);
    board.set(6, 1, ALIVE);

    EXPECT_EQ(board.countAliveNeighbors(5, 0), 5);
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

// TODO
TEST_F(neighborsTest, givesZeroAliveNeighborsForCellOnRightEdge)
{
    IGNORE();

    // Make everything alive

    EXPECT_EQ(board.countAliveNeighbors(NUM_COLS - 1, 5), 0);
}

// TODO
TEST_F(neighborsTest, givesZeroAliveNeighborsForCellOnBottomEdge)
{
    IGNORE();

    // Make everything alive

    EXPECT_EQ(board.countAliveNeighbors(5, NUM_ROWS - 1), 0);
}
