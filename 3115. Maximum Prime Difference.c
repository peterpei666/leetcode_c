#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

inline bool prime(int x)
{
    if(x==2)
    {
        return true;
    }
    if(x==1||x%2==0)
    {
        return false;
    }
    int i,limit;
    for(int i=3,limit=sqrt(x);i<=limit;i+=2)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}

int maximumPrimeDifference(int* nums, int n)
{
    int i,l=-1,r=-1;
    for(i=0;i<n;i++)
    {
        if(prime(nums[i]))
        {
            if(l==-1)
            {
                l=i;
            }
            r=i;
        }
    }
    return r-l;
}
