#include "Arduino.h"
#include <gtest/gtest.h>
#include "game.h"

using namespace ::testing;

class randomTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        initRandomMock();
    }
};

TEST_F(randomTest, shouldCallRandomSeedOnce)
{
    gameSetup();
    EXPECT_EQ(numCallsToRandSeed, 1);
}

TEST_F(randomTest, shouldPassMockedValueToRandomSeed)
{
    gameSetup();
    EXPECT_EQ(numPassedToRandSeed, MOCK_ANALOG_READ_RESULT);
}

TEST_F(randomTest, setupShouldCallAnalogReadOnce)
{
    gameSetup();
    EXPECT_EQ(numCallsToAnalogRead, 1);
}

TEST_F(randomTest, shouldPassCorrectPinNumberToAnalogRead)
{
    gameSetup();
    EXPECT_EQ(pinNumPassedToAnalogRead, 7);
}

TEST_F(randomTest, randomSeedIsCalledWithValueFromAnalogRead)
{
    gameSetup();
    EXPECT_EQ(numPassedToRandSeed, MOCK_ANALOG_READ_RESULT);
}
