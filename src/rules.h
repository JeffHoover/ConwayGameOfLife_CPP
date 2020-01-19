#ifndef _RULES_H_
#define _RULES_H_
#include "stdbool.h"

#define ALIVE true
#define DEAD !ALIVE

bool nextStateIsAlive(bool cellIsAlive, int numberOfNeighbors);
#endif
