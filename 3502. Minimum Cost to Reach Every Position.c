#include <stdio.h>
#include <stdlib.h>

inline int mini(int a,int b)
{
    return a<b?a:b;
}

int* minCosts(int* cost, int costSize, int* returnSize)
{
    int i;
    *returnSize=costSize;
    for(i=1;i<costSize;i++)
    {
        cost[i]=mini(cost[i],cost[i-1]);
    }
    return cost;
}
