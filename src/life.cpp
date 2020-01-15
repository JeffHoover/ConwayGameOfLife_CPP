#include "life.h"
#include "Arduino.h"
#include "string.h"

bool grid[NUM_ROWS][NUM_COLS];
bool altGrid[NUM_ROWS][NUM_COLS];

#define EMPTY_ANALOG_READ_PIN 7

void gameSetup()
{
    memset(grid, false, sizeof(grid));
    memset(altGrid, false, sizeof(altGrid)); // set altGrid all black

    int analogReadResult = analogRead(EMPTY_ANALOG_READ_PIN);
    randomSeed(analogReadResult);

    for (int x = 0; x < NUM_ROWS; x++)
    {
        for (int y = 0; y < NUM_COLS; y++)
        {
            grid[x][y] = (random(3) == 0);
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
    return false;
}

int countAliveNeighbors(int row, int col)
{
    // make cells on edges have zero alive neighbors
    // and die, just to simplify things.
    if (col >= NUM_COLS || col <= 0 ||
        row >= NUM_ROWS || row <= 0)
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