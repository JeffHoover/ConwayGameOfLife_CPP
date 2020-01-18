#include "Arduino.h"
#include <gtest/gtest.h>
#include "life.h"

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

TEST_F(random, gridCreationCallsRandomOncePerCellExceptAlwaysDeadBoarder)
{
    gameSetup();
    EXPECT_EQ(numTimesRandomCalled, (NUM_COLS - 2) * (NUM_ROWS - 2));
}

TEST_F(random, mainGridStartsFullOfDeadCells)
{

    gameSetup();

    bool expectedGrid[NUM_COLS][NUM_ROWS];
    memset(expectedGrid, DEAD, sizeof(expectedGrid));

    int result = memcmp(expectedGrid, grid, sizeof(grid));

    EXPECT_EQ(0, result);
}

TEST_F(random, altGridStartsFullOfDeadCells)
{

    gameSetup();

    bool expectedGrid[NUM_COLS][NUM_ROWS];
    memset(expectedGrid, DEAD, sizeof(expectedGrid));

    int result = memcmp(expectedGrid, altGrid, sizeof(altGrid));

    EXPECT_EQ(0, result);
}
