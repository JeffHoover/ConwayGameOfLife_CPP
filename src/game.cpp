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
    int aliveCount = 0;
    for (int ii = 0; ii < NUM_COLS; ii++)
    {
        for (int jj = 0; jj < NUM_ROWS; jj++)
            if (futureGeneration->get(ii, jj) == ALIVE)
            {
                aliveCount++;
            }
    }
    printf(" ZZ before aliveCount %d", aliveCount);
    fflush(stdout);

    for (uint8_t x = 0; x < NUM_COLS; ++x)
    {
        for (uint8_t y = 0; y < NUM_ROWS; ++y)
        {
            bool state = currentGeneration->get(x, y);
            int liveNeighborCount = currentGeneration->countAliveNeighbors(x, y);
            bool nextState = nextStateIsAlive(state, liveNeighborCount);
            if (nextState == ALIVE)
            {
                printf(" LE %d,%d [state %d] %d live neighbors. Will become %d\n", x, y, state, liveNeighborCount, nextState);
                fflush(stdout);
            }

            // if (state == ALIVE || liveNeighborCount == 3)
            // {
            //     printf(" LE %d,%d [state %d] %d live neighbors. Will become %d\n", x, y, state, liveNeighborCount, nextState);
            //     fflush(stdout);
            // }
            futureGeneration->set(x, y, nextState);
        }
    }

    aliveCount = 0;
    for (int ii = 0; ii < NUM_COLS; ii++)
    {
        for (int jj = 0; jj < NUM_ROWS; jj++)
            if (futureGeneration->get(ii, jj) == ALIVE)
            {
                aliveCount++;
            }
    }
    printf(" ZZ after aliveCount %d\n", aliveCount);
    fflush(stdout);

    tmpGeneration = futureGeneration;
    futureGeneration = currentGeneration;
    currentGeneration = tmpGeneration;

    aliveCount = 0;
    for (int ii = 0; ii < NUM_COLS; ii++)
    {
        for (int jj = 0; jj < NUM_ROWS; jj++)
            if (currentGeneration->get(ii, jj) == ALIVE)
            {
                aliveCount++;
                printf("ZZ [%d,%d]   ", ii, jj);
            }
    }
    printf(" ZZ after swap aliveCount %d\n", aliveCount);
    fflush(stdout);

    display();
}

void display()
{
    // display currentGeneration
}