#include "Arduino.h"

int numCallsToRandSeed;
int numCallsToAnalogRead;
uint8_t pinNumPassedToAnalogRead;
unsigned long numPassedToRandSeed;
int numTimesRandomCalled;
int randomToReturn;

void mockInit() {
    numCallsToRandSeed = 0;
    numCallsToAnalogRead = 0;
    numTimesRandomCalled = 0;
    pinNumPassedToAnalogRead = UINT8_MAX;
    numPassedToRandSeed = __LONG_MAX__;
    randomToReturn = 1;
}

void randomSeed(unsigned long number) {
    numCallsToRandSeed++;
    numPassedToRandSeed = number;
}

int analogRead(uint8_t pin) {
    pinNumPassedToAnalogRead = pin;
    numCallsToAnalogRead++;
    return ANALOG_READ_RESULT;
}

long random(long upperBound) 
{
    numTimesRandomCalled++;
    return randomToReturn;
}