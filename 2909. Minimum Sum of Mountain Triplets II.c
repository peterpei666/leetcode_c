#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static inline int min(int a,int b)
{
    return a<b?a:b;
}

int minimumSum(int* nums, int n)
{
    int i,ans;
    int prefix[n];
    int suffix[n];
    prefix[0]=nums[0];
    for(i=1;i<n;i++)
    {
        prefix[i]=min(prefix[i-1],nums[i]);
    }
    suffix[n-1]=nums[n-1];
    for(i=n-2;i>=0;i--)
    {
        suffix[i]=min(suffix[i+1],nums[i]);
    }
    ans=INT_MAX;
    for(i=1;i<n-1;i++)
    {
        if(nums[i]>prefix[i]&&nums[i]>suffix[i])
        {
            ans=min(ans,prefix[i]+nums[i]+suffix[i]);
        }
    }
    return ans==INT_MAX?-1:ans;
}
