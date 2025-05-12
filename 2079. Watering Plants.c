#include <stdio.h>
#include <stdlib.h>

int wateringPlants(int* plants, int plantsSize, int capacity)
{
    int ret=0,t=capacity,i;
    for(i=0;i<plantsSize;i++)
    {
        ret++;
        if(t<plants[i])
        {
            t=capacity;
            ret+=2*i;
        }
        t-=plants[i];
    }
    return ret;
}
