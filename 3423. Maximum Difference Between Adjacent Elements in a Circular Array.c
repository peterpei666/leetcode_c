#include <stdio.h>
#include <stdlib.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int maxAdjacentDistance(int* nums, int n)
{
    int i;
    int ans=abs(nums[n-1]-nums[0]);
    for(i=1;i<n;i++)
    {
        ans=max(ans,abs(nums[i]-nums[i-1]));
    }
    return ans;
}
