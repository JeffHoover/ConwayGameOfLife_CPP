#include "game.h"
#include "Arduino.h"

void gameSetup()
{
    int analogReadResult = analogRead(EMPTY_ANALOG_READ_PIN);
    randomSeed(analogReadResult);
}

void gameLoop()
{
}
