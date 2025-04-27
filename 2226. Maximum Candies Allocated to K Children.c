#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool can(int n,int* candies,int candiesSize,long long k)
{
    int i;
    for(i=0;i<candiesSize;i++)
    {
        k-=candies[i]/n;
        if(k<=0)
        {
            return true;
        }
    }
    return false;
}

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maximumCandies(int* candies, int candiesSize, long long k)
{
    int i,mid,left=0,right=0;
    for(i=0;i<candiesSize;i++)
    {
        right=maxi(right,candies[i]);
    }
    while(left<right)
    {
        mid=left+(-left+right+1)/2;
        if(can(mid,candies,candiesSize,k))
        {
            left=mid;
        }
        else
        {
            right=mid-1;
        }
    }
    return left;
}
