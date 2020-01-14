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

TEST_F(random, shouldPassCorrectValueToRandomSeed)
{
    gameSetup();
    EXPECT_EQ(numPassedToRandSeed, ANALOG_READ_RESULT);
}

TEST_F(random, shouldCallAnalogRead)
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
    EXPECT_EQ(numPassedToRandSeed, ANALOG_READ_RESULT);
}

TEST_F(random, gridCreationCallsRandomCorrectNumberOfTimes)
{
    gameSetup();
    EXPECT_EQ(numTimesRandomCalled, 2 * sizeof(grid));
}

TEST_F(random, mainGridIsFullOfRandomZeroes) {

gameSetup();
bool expectedGrid [NUM_ROWS][NUM_COLS];
memset(expectedGrid, false, sizeof(expectedGrid));

int result = memcmp(expectedGrid, grid, sizeof(grid));

EXPECT_EQ(0, result);
}

TEST_F(random, altGridIsFullOfRandomOnes) {

gameSetup();

bool expectedGrid [NUM_ROWS][NUM_COLS];
memset(expectedGrid, true, sizeof(expectedGrid));

int result = memcmp(expectedGrid, altGrid, sizeof(altGrid));

EXPECT_EQ(0, result);
}


// TEST_F(display, setsRightNumberOfPixels) {

//     grid[1][1] = true;
//     grid[2][2] = true;
//     grid[3][3] = true;
//     grid[14][4] = true;
//     grid[5][5] = true;

//     testMatrix.display(grid);

//     EXPECT_EQ(testMatrix.getPixelAssignmentCount(), 5);
// }