#include "game.h"
#include "board.h"
#include "rules.h"
#include "Arduino.h"
#include "stdio.h" // for printf

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
    for (uint8_t x = 0; x < NUM_COLS; ++x)
    {
        for (uint8_t y = 0; y < NUM_ROWS; ++y)
        {
            bool state = currentGeneration->get(x, y);
            int liveNeighborCount = currentGeneration->countAliveNeighbors(x, y);
            bool nextState = nextStateIsAlive(state, liveNeighborCount);
            futureGeneration->set(x, y, nextState);
        }
    }

    tmpGeneration = futureGeneration;
    futureGeneration = currentGeneration;
    currentGeneration = tmpGeneration;

    display();
}

void display()
{
    // display currentGeneration
}