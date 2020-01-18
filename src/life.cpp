#include "life.h"
#include "Arduino.h"
#include "string.h"

bool grid[NUM_COLS][NUM_ROWS];
bool altGrid[NUM_COLS][NUM_ROWS];

char buf[60];

#define EMPTY_ANALOG_READ_PIN 7

extern int grey;

void gameSetup()
{
    memset(grid, DEAD, sizeof(grid));
    memset(altGrid, DEAD, sizeof(grid));

    int analogReadResult = analogRead(EMPTY_ANALOG_READ_PIN);
    randomSeed(analogReadResult);

    for (int x = 1; x < NUM_COLS - 1; x++)
    {
        for (int y = 1; y < NUM_ROWS - 1; y++)
        {
            bool aliveOrDead = (random(3) == 0);
            grid[x][y] = aliveOrDead;
            altGrid[x][y] = aliveOrDead;
        }
    }
}

bool nextStateIsAlive(bool cellIsAlive, int numberOfNeighbors)
{
    if (numberOfNeighbors == 2 && !cellIsAlive)
    {
        return DEAD;
    }
    if (numberOfNeighbors > 1 && numberOfNeighbors < 4)
    {
        return ALIVE;
    }
    return DEAD;
}

int countAliveNeighbors(int row, int col)
{
    // make cells on edges have zero alive neighbors
    // and die, just to simplify things.
    if (col >= NUM_ROWS - 1 || col <= 0 ||
        row >= NUM_COLS - 1 || row <= 0)
    {
        return 0;
    }

    int aliveNeighborCount = 0;
    if (grid[row][col + 1])
    {
        aliveNeighborCount++;
    }
    if (grid[row][col - 1])
    {
        aliveNeighborCount++;
    }
    if (grid[row - 1][col])
    {
        aliveNeighborCount++;
    }
    if (grid[row + 1][col])
    {
        aliveNeighborCount++;
    }
    if (grid[row - 1][col - 1])
    {
        aliveNeighborCount++;
    }
    if (grid[row - 1][col + 1])
    {
        aliveNeighborCount++;
    }
    if (grid[row + 1][col - 1])
    {
        aliveNeighborCount++;
    }
    if (grid[row + 1][col + 1])
    {
        aliveNeighborCount++;
    }
    return aliveNeighborCount;
}

extern "C"
{
    void computeGeneration(bool *const current, bool *const next)
    {
        int numPix = 0;
        bool *currentGrid = current;
        bool *nextGrid = next;
        // sprintf(buf, "currentGrid = %d, nextGrid=%d", currentGrid, nextGrid);
        // Serial.println(buf);
        // Serial.flush();

        currentGrid += NUM_COLS + 1;
        nextGrid += NUM_COLS + 1;
        for (int x = 1; x < NUM_COLS - 1; x++)
        {
            for (int y = 1; y < NUM_ROWS - 1; y++)
            {
                int count = countAliveNeighbors(x, y);
                bool nextState = nextStateIsAlive(*currentGrid > 0, count);
                *nextGrid = nextState;
                currentGrid++;
                nextGrid++;
                numPix++;
            }
        }

        //sprintf(buf, "Calculated %d pixels, memcmp = %d.", numPix, memcmp(currentGrid, nextGrid, (NUM_ROWS - 2) * (NUM_COLS - 2)));
        //Serial.println(buf);
        // Serial.flush();
    }
}
