#include <stdio.h>
#include <stdlib.h>

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

int maxCoins(int* piles, int pilesSize)
{
    int i,sum=0;
    qsort(piles,pilesSize,sizeof(int),compare);
    for(i=pilesSize-2;i>=pilesSize/3;i-=2)
    {
        sum+=piles[i];
    }
    return sum;
}
