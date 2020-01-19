#include "rules.h"

bool nextStateIsAlive(bool cellIsAlive, int numberOfNeighbors)
{
    if (numberOfNeighbors == 2 && !cellIsAlive)
    {
        return DEAD;
    }
    if (numberOfNeighbors > 1 && numberOfNeighbors < 4)
    {
        return ALIVE;
    }
    return DEAD;
}
