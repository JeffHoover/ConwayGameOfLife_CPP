#include "Arduino.h"
#include <gtest/gtest.h>
#include "game.h"

using namespace ::testing;

class random : public ::testing::Test
{
protected:
    void SetUp() override
    {
        mockInit();
    }
};

TEST_F(random, shouldCallRandomSeedOnce)
{
    gameSetup();
    EXPECT_EQ(numCallsToRandSeed, 1);
}

TEST_F(random, shouldPassMockedValueToRandomSeed)
{
    gameSetup();
    EXPECT_EQ(numPassedToRandSeed, MOCK_ANALOG_READ_RESULT);
}

TEST_F(random, setupShouldCallAnalogReadOnce)
{
    gameSetup();
    EXPECT_EQ(numCallsToAnalogRead, 1);
}

TEST_F(random, shouldPassCorrectPinNumberToAnalogRead)
{
    gameSetup();
    EXPECT_EQ(pinNumPassedToAnalogRead, 7);
}

TEST_F(random, randomSeedIsCalledWithValueFromAnalogRead)
{
    gameSetup();
    EXPECT_EQ(numPassedToRandSeed, MOCK_ANALOG_READ_RESULT);
}
