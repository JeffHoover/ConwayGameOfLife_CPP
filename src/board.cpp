#include "board.h"
#include "string.h"
#include "stdio.h" // for printf

char buf[60];

void Board::kill()
{
    memset(cells, DEAD, NUM_COLS * NUM_ROWS);
}

void Board::set(uint8_t x, uint8_t y, bool state)
{
    cells[x][y] = state;
}

bool Board::get(uint8_t x, uint8_t y)
{
    return cells[x][y];
}

uint8_t Board::countAliveNeighbors(uint8_t x, uint8_t y)
{
    uint8_t count = 0;
    uint8_t xlb = x == 0 ? 0 : x - 1;
    uint8_t xub = x >= NUM_COLS - 1 ? NUM_COLS - 1 : x + 1;
    uint8_t ylb = y == 0 ? 0 : y - 1;
    uint8_t yub = y >= NUM_ROWS - 1 ? NUM_ROWS - 1 : y + 1;

    for (uint8_t i = xlb; i <= xub; ++i)
    {
        for (uint8_t j = ylb; j <= yub; ++j)
        {
            if (x == i && y == j)
            {
                continue;
            }
            if (get(i, j))
            {
                ++count;
            }
        }
    }
    return count;
}
