#include "rules.h"

bool nextStateIsAlive(bool cellIsAlive, int numberOfAliveNeighbors)
{
    if (numberOfAliveNeighbors == 2 && !cellIsAlive)
    {
        return DEAD;
    }
    if (numberOfAliveNeighbors > 1 && numberOfAliveNeighbors < 4)
    {
        return ALIVE;
    }
    return DEAD;
}
