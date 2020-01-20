#include "rules.h"
#include "stdio.h" // for printf

bool nextStateIsAlive(bool cellIsAlive, int numberOfAliveNeighbors)
{
    if (cellIsAlive || numberOfAliveNeighbors == 3)
    {
        printf("\n\na %d LE liveNeighbors --- ", numberOfAliveNeighbors);
    }
    if (numberOfAliveNeighbors == 2 && !cellIsAlive)
    {
        if (cellIsAlive)
        {
            printf("LE b\n");
        }
        return DEAD;
    }
    if (numberOfAliveNeighbors > 1 && numberOfAliveNeighbors < 4)
    {
        if (cellIsAlive)
        {
            printf("LE d\n");
        }
        return ALIVE;
    }
    if (cellIsAlive)
    {
        printf("LE e %d \n", numberOfAliveNeighbors);
    }
    return DEAD;
}
