#include "life.h"
#include "Arduino.h"
#include "string.h"

bool grid[NUM_ROWS][NUM_COLS];
bool altGrid[NUM_ROWS][NUM_COLS];

#define EMPTY_ANALOG_READ_PIN 7

void gameSetup()
{
    memset(grid, false, sizeof(grid));
    memset(altGrid, false, sizeof(altGrid));

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

    int neighbors = 0;
    if (grid[row][col + 1])
    {
        neighbors++;
    }
    if (grid[row][col - 1])
    {
        neighbors++;
    }
    if (grid[row - 1][col])
    {
        neighbors++;
    }
    if (grid[row + 1][col])
    {
        neighbors++;
    }
    if (grid[row - 1][col - 1])
    {
        neighbors++;
    }
    if (grid[row - 1][col + 1])
    {
        neighbors++;
    }
    if (grid[row + 1][col - 1])
    {
        neighbors++;
    }
    if (grid[row + 1][col + 1])
    {
        neighbors++;
    }
    return neighbors;
}