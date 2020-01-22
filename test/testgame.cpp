#include "Arduino.h"
#include <gtest/gtest.h>
#include "game.h"
#include "board.h"

using namespace ::testing;

class gameTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        initRandomMock();
    }
    Board *board = currentGeneration;
};

TEST_F(gameTest, canApplyRules)
{
    board->kill();

    //Create a "blinker":
    board->set(3, 2, ALIVE);
    board->set(3, 3, ALIVE);
    board->set(3, 4, ALIVE);

    gameLoop();
    board = currentGeneration; // currentGeneration has changed, point at it again before doing assertions;

    EXPECT_EQ(board->get(2, 3), ALIVE);
    EXPECT_EQ(board->get(3, 3), ALIVE);
    EXPECT_EQ(board->get(4, 3), ALIVE);

    EXPECT_EQ(board->get(3, 2), DEAD);
    EXPECT_EQ(board->get(3, 4), DEAD);
}