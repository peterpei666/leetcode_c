#include <stdio.h>
#include <stdlib.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int longestMonotonicSubarray(int* nums, int n)
{
    int i;
    int l=1,temp=1;
    for(i=1;i<n;i++)
    {
        if(nums[i]>nums[i-1])
        {
            temp++;
        }
        else
        {
            l=max(l,temp);
            temp=1;
        }
    }
    l=max(l,temp);
    temp=1;
    for(i=1;i<n;i++)
    {
        if(nums[i]<nums[i-1])
        {
            temp++;
        }
        else
        {
            l=max(l,temp);
            temp=1;
        }
    }
    l=max(l,temp);
    return l;
}
