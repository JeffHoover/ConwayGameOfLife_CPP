#include "board.h"
#include "stdio.h"

char buf[60];
void Board::set(uint8_t x, uint8_t y, bool state)
{
    printf("Setting %d,%d = %d", x,y,state);
    cells[x][y] = state;
}

bool Board::get(uint8_t x, uint8_t y)
{
    return cells[x][y];
}

uint8_t Board::livingNeighbors(uint8_t x, uint8_t y)
{
    return -1;
}
