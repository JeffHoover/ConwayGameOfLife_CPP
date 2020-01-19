computeGeneration(*altGrid, *grid, NUM_ROWS, NUM_COLS);
display(*grid, &matrix);
// Red pixel for frame indicator and 0,0 orientation
matrix.drawPixel(2, 2, matrix.Color333(7, 0, 0));
matrix.drawPixel(60, 2, matrix.Color333(0, 7, 7));
// delay(1000);

computeGeneration(*grid, *altGrid, NUM_ROWS, NUM_COLS);
display(*grid, &matrix);
// Blue pixel for frame indicator and 0,0 orientation
matrix.drawPixel(2, 2, matrix.Color333(0, 0, 7));
matrix.drawPixel(60, 2, matrix.Color333(0, 7, 7));
// delay(1000);
}

void display(bool *current, RGBmatrixPanel *myMatrix)
{
  int numPix = 0;
  for (int x = 0; x < NUM_COLS; x++)
  {
    for (int y = 0; y < NUM_ROWS; y++)
    {
      bool *cellIsAlive = current + (x * NUM_ROWS + y);

      uint8_t colorIntensity = *cellIsAlive * 3;
      myMatrix->drawPixel(x, y, myMatrix->Color333(colorIntensity, colorIntensity, colorIntensity));

      numPix++;
    }
  }

  sprintf(buf, "displayed %d pixels\n", numPix);
  Serial.println(buf);
  Serial.flush();
}

#define NUM_ROWS 32
#define NUM_COLS 64

#define ALIVE true
#define DEAD !ALIVE

extern bool grid[NUM_COLS][NUM_ROWS];
extern bool altGrid[NUM_COLS][NUM_ROWS];
extern bool first[4][4];
extern bool second[4][4];

int countAliveNeighbors(int x, int y);
void gameSetup();

extern "C"
{
  void computeGeneration(bool *, bool *, int, int);
}

#include "string.h"
#include <stdio.h>

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
