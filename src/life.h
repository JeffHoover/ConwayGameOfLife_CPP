#ifndef _LIFE_H_
#define _LIFE_H_

#define NUM_ROWS 64
#define NUM_COLS 32

extern bool grid[NUM_ROWS][NUM_COLS];
extern bool altGrid[NUM_ROWS][NUM_COLS];

bool applyRules(bool cellIsAlive, int numberOfNeighbors);
int countNeighbors(int x, int y);
void gameSetup();

#endif