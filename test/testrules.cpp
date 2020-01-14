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
    bool cellIsAlive = true;
    int neighborCount = 1;

    EXPECT_EQ(nextStateIsAlive(cellIsAlive, neighborCount), false);
}
TEST_F(rules, liveCellWithTwoLiveNeighborsLives)
{
    bool cellIsAlive = true;
    int neighborCount = 2;

    EXPECT_EQ(nextStateIsAlive(cellIsAlive, neighborCount), true);
}
TEST_F(rules, liveCellWithTrheeLiveNeighborsLives)
{
    bool cellIsAlive = true;
    int neighborCount = 3;

    EXPECT_EQ(nextStateIsAlive(cellIsAlive, neighborCount), true);
}
TEST_F(rules, liveCellWithMoreThanThreeLiveNeighborsDies)
{
    bool cellIsAlive = true;
    int neighborCount = 4;

    EXPECT_EQ(nextStateIsAlive(cellIsAlive, neighborCount), false);
}
TEST_F(rules, deadCellWithThreeNeighborsComesToLife)
{
    bool cellIsAlive = false;
    int neighborCount = 3;

    EXPECT_EQ(nextStateIsAlive(cellIsAlive, neighborCount), true);
}
TEST_F(rules, deadCellWithTwoNeighborsStaysDead)
{
    bool cellIsAlive = false;
    int neighborCount = 2;

    EXPECT_EQ(nextStateIsAlive(cellIsAlive, neighborCount), false);
}
