#ifndef _GAME_H_
#define _GAME_H_

#include "board.h"

#define EMPTY_ANALOG_READ_PIN 13

void gameSetup(void);
void gameLoop(void);
void display();

extern Board board1;
extern Board board2;
extern Board *currentGeneration;

#endif

