#ifndef _LIFE_H_
#define _LIFE_H_

#define NUM_ROWS 64
#define NUM_COLS 32

#define ALIVE true
#define DEAD !ALIVE

extern bool grid[NUM_ROWS][NUM_COLS];
extern bool altGrid[NUM_ROWS][NUM_COLS];

bool nextStateIsAlive(bool cellIsAlive, int numberOfNeighbors);
int countAliveNeighbors(int x, int y);
void gameSetup();

#endif