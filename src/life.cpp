#include "life.h"
#include "Arduino.h"
#include "string.h"
#include <stdio.h>

#if 0
bool first[4][4];
bool second[4][4];
bool grid[NUM_COLS][NUM_ROWS];
bool altGrid[NUM_COLS][NUM_ROWS];

#define EMPTY_ANALOG_READ_PIN 7

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





extern "C"
{
    void computeGeneration(bool *const current, bool *const next, int rows, int cols)
    {
        int numPix = 0;
        int numSwitched = 0;
        bool *currentGrid = current;
        bool *nextGrid = next;

        printf("BEFORE (first)\n");
        printf("\n");
        for (int ii = 0; ii < 4; ii++)
        {
            for (int jj = 0; jj < 4; jj++)
            {
                printf("%d  ", first[ii][jj]);
            }
            printf("\n");
        }
        printf("\n");

        for (int x = 0; x < cols; x++)
        {
            for (int y = 0; y < rows; y++)
            {
                numPix++;

                if (y > 0 && y < rows - 1 && x > 0 && x < cols - 1)
                {
                    // int count = countAliveNeighbors(rows, cols, current, x, y);
                    int count = 0;
                    printf("(%d neighbors)\n", count);

                    bool nextState = nextStateIsAlive(*currentGrid, count);
                    if (nextState != *currentGrid)
                    {
                        printf("Switching [%d, %d] from %d to %d.\n", x, y, *currentGrid, nextState);
                        numSwitched++;
                    }
                    else
                    {
                        printf("[%d, %d] stays %d\n", x, y, *currentGrid);
                    }
                    *nextGrid = nextState;
                }
                else
                {
                    printf("Edge pixel [%d,%d]\n", x, y);
                }
                currentGrid++;
                nextGrid++;
            }
        }

        printf("\nOperated on %d pixels. Switched %d pixels.\n\n", numPix, numSwitched);
    }
}
#endif