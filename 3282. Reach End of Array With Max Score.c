#include <stdio.h>
#include <stdlib.h>

long long findMaximumScore(int* nums, int n)
{
    long long ans=0;
    int i;
    int prev=0;
    for(i=1;i<n;i++)
    {
        if(nums[i]>nums[prev])
        {
            ans+=(long long)nums[prev]*(i-prev);
            prev=i;
        }
    }
    ans+=(long long)(n-1-prev)*nums[prev];
    return ans;
}
