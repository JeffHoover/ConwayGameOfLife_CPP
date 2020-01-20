#include "game.h"
#include "board.h"
#include "Arduino.h"

Board board1;
Board board2;

Board *currentGeneration = &board1;
Board *futureGeneration = &board2;
Board *tmpGeneration;

void gameSetup()
{
    int analogReadResult = analogRead(EMPTY_ANALOG_READ_PIN);
    randomSeed(analogReadResult);

    // TODO - populate board1
    // Test number of times random is called: numTimesRandomCalled
}

void gameLoop()
{
    tmpGeneration = futureGeneration;
    futureGeneration = currentGeneration;
    currentGeneration = tmpGeneration;

    display();
}

void display()
{
    // display currentGeneration
}