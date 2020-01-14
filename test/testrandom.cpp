#include "Arduino.h"
#include <gtest/gtest.h>
#include "life.h"

using namespace ::testing;

class random : public ::testing::Test {
 protected:
  void SetUp() override {
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

TEST_F(random, gridCreationCallsRandomOncePerCell)
{
    gameSetup();
    EXPECT_EQ(numTimesRandomCalled, sizeof(grid));
}

TEST_F(random, mainGridStartsFullOfRandomZeroes) {

        gameSetup();

        bool expectedGrid [NUM_ROWS][NUM_COLS];
        memset(expectedGrid, false, sizeof(expectedGrid));

        int result = memcmp(expectedGrid, grid, sizeof(grid));

        EXPECT_EQ(0, result);
}

TEST_F(random, altGridStartsFullOfZeros) {

    gameSetup();

    bool expectedGrid [NUM_ROWS][NUM_COLS];
    memset(expectedGrid, false, sizeof(expectedGrid));

    int result = memcmp(expectedGrid, altGrid, sizeof(altGrid));

    EXPECT_EQ(0, result);
}


