#include "board.h"
#include "rules.h"
#include <gtest/gtest.h>
#include <stdio.h>

#define IGNORE GTEST_SKIP

class BoardTest : public testing::Test
{
protected:
  Board board;
};

TEST_F(BoardTest, CellDefaultsToDead)
{
  EXPECT_EQ(board.get(7, 7), DEAD);
}

TEST_F(BoardTest, CanSetCellAlive)
{
  board.set(7, 7, ALIVE);
  EXPECT_EQ(board.get(7, 7), ALIVE);
}

TEST_F(BoardTest, CanSetCellAliveThenDead)
{
  board.set(4, 4, ALIVE);
  EXPECT_TRUE(board.get(4, 4));

  board.set(4, 4, DEAD);
  EXPECT_FALSE(board.get(4, 4));
}

TEST_F(BoardTest, CellWithNoLiveNeighbors_Returns0)
{
  IGNORE();
  EXPECT_EQ(0, board.livingNeighbors(4, 4));
}

TEST_F(BoardTest, CellWithOneLiveNeighbor_Returns1)
{
  IGNORE();

  board.set(3, 3, ALIVE);
  EXPECT_EQ(1, board.livingNeighbors(4, 4));
}

TEST_F(BoardTest, LiveCellWithAllLiveNeighbors_Returns8)
{
  IGNORE();

  for (uint8_t x = 3; x < 6; ++x)
  {
    for (uint8_t y = 3; y < 6; ++y)
    {
      board.set(x, y, ALIVE);
    }
  }
  EXPECT_EQ(8, board.livingNeighbors(4, 4));
}

TEST_F(BoardTest, Neighbors_AtCornerOnFullBoard_Returns3)
{
  IGNORE();

  for (uint8_t x = 0; x < NUM_COLS; ++x)
  {
    for (uint8_t y = 0; y < NUM_ROWS; ++y)
    {
      board.set(x, y, ALIVE);
    }
  }
  ASSERT_TRUE(board.get(0, 1));
  ASSERT_TRUE(board.get(1, 0));
  ASSERT_TRUE(board.get(1, 1));
  EXPECT_EQ(3, board.livingNeighbors(0, 0));
  //   EXPECT_EQ(3, board.livingNeighbors(0, YMAX - 1));
  //   EXPECT_EQ(3, board.livingNeighbors(XMAX - 1, 0));
  //   EXPECT_EQ(3, board.livingNeighbors(XMAX - 1, YMAX - 1));
}
