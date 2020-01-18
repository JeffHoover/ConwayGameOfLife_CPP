#ifndef _ARDUINO_H_
#define _ARDUINO_H_

// THIS MUST BE NAMED Arduino.h BECAUSE IT IS USED
// BY BOTH THE TESTING/MOCKING AND PROD CODE PROJECTS

#include <stdint.h>

#define MOCK_ANALOG_READ_RESULT 37

extern int numCallsToRandSeed;
extern int numCallsToAnalogRead;
extern uint8_t pinNumPassedToAnalogRead;
extern unsigned long numPassedToRandSeed;
extern int numTimesRandomCalled;
extern int randomToReturn;
void randomSeed(unsigned long);
int analogRead(uint8_t pin);
long random(long upperBound);
void mockInit();

#endif