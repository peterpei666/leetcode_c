#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maxProfit(int* prices, int pricesSize, int fee)
{
    int prev=0,old=0,c0=0,c1=INT_MIN;
    int i;
    for(i=0;i<pricesSize;i++)
    {
        old=c0;
        c0=maxi(c0,c1+prices[i]);
        c1=maxi(c1,old-prices[i]-fee);
    }
    return c0;
}
