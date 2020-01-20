#include "board.h"
#include "rules.h"
#include <gtest/gtest.h>
#include <stdio.h>

#define IGNORE GTEST_SKIP

class boardTest : public testing::Test
{
public:
  Board board;

  void SetUp() override
  {
    board.kill();
  }
};

TEST_F(boardTest, CellDefaultsToDead)
{
  EXPECT_EQ(board.get(7, 7), DEAD);
}

TEST_F(boardTest, CanSetCellAlive)
{
  board.set(7, 7, ALIVE);
  EXPECT_EQ(board.get(7, 7), ALIVE);
}

TEST_F(boardTest, CanSetCellAliveThenDead)
{
  board.set(4, 4, ALIVE);
  EXPECT_TRUE(board.get(4, 4));

  board.set(4, 4, DEAD);
  EXPECT_FALSE(board.get(4, 4));
}

TEST_F(boardTest, CellWithNoLiveNeighbors_Returns0)
{
  EXPECT_EQ(0, board.countAliveNeighbors(4, 4));
}

TEST_F(boardTest, CellWithOneLiveNeighbor_Returns1)
{
  board.set(3, 3, ALIVE);
  EXPECT_EQ(1, board.countAliveNeighbors(4, 4));
}

TEST_F(boardTest, LiveCellWithAllLiveNeighbors_Returns8)
{
  for (uint8_t x = 3; x < 6; ++x)
  {
    for (uint8_t y = 3; y < 6; ++y)
    {
      board.set(x, y, ALIVE);
    }
  }
  EXPECT_EQ(8, board.countAliveNeighbors(4, 4));
}

TEST_F(boardTest, Neighbors_AtCornerOnFullBoard_Returns3)
{
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
  EXPECT_EQ(3, board.countAliveNeighbors(0, 0));
  //   EXPECT_EQ(3, board.countAliveNeighbors(0, YMAX - 1));
  //   EXPECT_EQ(3, board.countAliveNeighbors(XMAX - 1, 0));
  //   EXPECT_EQ(3, board.countAliveNeighbors(XMAX - 1, YMAX - 1));
}
