#include "Arduino.h"
#include <gtest/gtest.h>
#include "rules.h"

using namespace ::testing;

class rulesTest : public ::testing::Test
{
};

TEST_F(rulesTest, liveCellWithFewerThanTwoLiveNeighborsDies)
{
    int neighborCount = 1;

    EXPECT_EQ(nextStateIsAlive(ALIVE, neighborCount), DEAD);
}
TEST_F(rulesTest, liveCellWithTwoLiveNeighborsLives)
{
    int neighborCount = 2;

    EXPECT_EQ(nextStateIsAlive(ALIVE, neighborCount), ALIVE);
}
TEST_F(rulesTest, liveCellWithTrheeLiveNeighborsLives)
{
    int neighborCount = 3;

    EXPECT_EQ(nextStateIsAlive(ALIVE, neighborCount), ALIVE);
}
TEST_F(rulesTest, liveCellWithMoreThanThreeLiveNeighborsDies)
{
    int neighborCount = 4;

    EXPECT_EQ(nextStateIsAlive(ALIVE, neighborCount), DEAD);
}
TEST_F(rulesTest, deadCellWithThreeNeighborsComesToLife)
{
    int neighborCount = 3;

    EXPECT_EQ(nextStateIsAlive(DEAD, neighborCount), ALIVE);
}
TEST_F(rulesTest, deadCellWithTwoNeighborsStaysDead)
{
    int neighborCount = 2;

    EXPECT_EQ(nextStateIsAlive(DEAD, neighborCount), DEAD);
}
