#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize)
{
    int i;
    qsort(asteroids,asteroidsSize,sizeof(int),cmp);
    for(i=0;i<asteroidsSize;i++)
    {
        if(mass>=asteroids[asteroidsSize-1])
        {
            return true;
        }
        if(mass>=asteroids[i])
        {
            mass+=asteroids[i];
        }
        else
        {
            return false;
        }
    }
    return true;
}
