#include "Arduino.h"
#include <gtest/gtest.h>
#include "life.h"

using namespace ::testing;

class rules : public ::testing::Test
{
protected:
    void SetUp() override
    {
        mockInit();
    }
};

TEST_F(rules, liveCellWithFewerThanTwoLiveNeighborsDies)
{
    int neighborCount = 1;

    EXPECT_EQ(nextStateIsAlive(ALIVE, neighborCount), DEAD);
}
TEST_F(rules, liveCellWithTwoLiveNeighborsLives)
{
    int neighborCount = 2;

    EXPECT_EQ(nextStateIsAlive(ALIVE, neighborCount), ALIVE);
}
TEST_F(rules, liveCellWithTrheeLiveNeighborsLives)
{
    int neighborCount = 3;

    EXPECT_EQ(nextStateIsAlive(ALIVE, neighborCount), ALIVE);
}
TEST_F(rules, liveCellWithMoreThanThreeLiveNeighborsDies)
{
    int neighborCount = 4;

    EXPECT_EQ(nextStateIsAlive(ALIVE, neighborCount), false);
}
TEST_F(rules, deadCellWithThreeNeighborsComesToLife)
{
    int neighborCount = 3;

    EXPECT_EQ(nextStateIsAlive(DEAD, neighborCount), ALIVE);
}
TEST_F(rules, deadCellWithTwoNeighborsStaysDead)
{
    int neighborCount = 2;

    EXPECT_EQ(nextStateIsAlive(DEAD, neighborCount), DEAD);
}
