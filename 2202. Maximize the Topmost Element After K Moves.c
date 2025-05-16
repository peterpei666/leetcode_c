#include <stdio.h>
#include <stdlib.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maximumTop(int* nums, int n, int k)
{
    int m=0;
    if(n==1&&k%2)
    {
        return -1;
    }
    if(k==1)
    {
        return nums[1];
    }
    for(int i=0;i<k-1&&i<n;i++)
    {
        m=maxi(m,nums[i]);
    }
    if(k<n)
    {
        m=maxi(m,nums[k]);
    }
    return m;
}
