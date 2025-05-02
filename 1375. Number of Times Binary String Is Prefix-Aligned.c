#include <stdio.h>
#include <stdlib.h>

int numTimesAllBlue(int* flips, int flipsSize)
{
    int count=0,maxPos=0,i;
    for(i=0;i<flipsSize;i++)
    {
        if(flips[i]>maxPos)
        {
            maxPos=flips[i];
        }
        if(maxPos==i+1)
        {
            count++;
        }
    }
    return count;
}
