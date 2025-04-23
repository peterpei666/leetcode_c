#include <stdio.h>
#include <stdlib.h>

inline long long maxi(long long a,long long b)
{
    return a>b?a:b;
}

inline long long mini(long long a,long long b)
{
    return a>b?b:a;
}

long long gridGame(int** grid, int gridSize, int* gridColSize)
{
    unsigned short i;
    long long sum1=0,ret,sum2=0;
    for(i=1;i<gridColSize[0];i++)
    {
        sum1+=grid[0][i];
    }
    ret=sum1;
    for(i=1;i<gridColSize[0];i++)
    {
        sum2+=grid[1][i-1];
        sum1-=grid[0][i];
        ret=mini(ret,maxi(sum1,sum2));
    }
    return ret;
}
