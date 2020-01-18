#ifndef _LIFE_H_
#define _LIFE_H_

#define NUM_ROWS 32
#define NUM_COLS 64

#define ALIVE true
#define DEAD !ALIVE

extern bool grid[NUM_COLS][NUM_ROWS];
extern bool altGrid[NUM_COLS][NUM_ROWS];

bool nextStateIsAlive(bool cellIsAlive, int numberOfNeighbors);
int countAliveNeighbors(int x, int y);
void gameSetup();

extern "C" {
void computeGeneration(bool *, bool *);
}

#endif