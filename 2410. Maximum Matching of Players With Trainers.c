#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

int matchPlayersAndTrainers(int* players, int playersSize, int* trainers, int trainersSize)
{
    int i,j,count;
    qsort(players,playersSize,sizeof(int),compare);
    qsort(trainers,trainersSize,sizeof(int),compare);
    i=playersSize-1;
    j=trainersSize-1;
    count=0;
    while(i>=0&&j>=0)
    {
        if(trainers[j]>=players[i])
        {
            count++;
            i--;
            j--;
        }
        else
        {
            i--;
        }
    }
    return count;
}
