#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int maximumDifference(int* nums, int n)
{
    int i,ans=-1;
    int suffix[n];
    suffix[n-1]=nums[n-1];
    for(i=n-2;i>=0;i--)
    {
        suffix[i]=max(suffix[i+1],nums[i]);
    }
    for(i=0;i<n-1;i++)
    {
        if(nums[i]<suffix[i+1])
        {
            ans=max(ans,suffix[i+1]-nums[i]);
        }
    }
    return ans;
}
