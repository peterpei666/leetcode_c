#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int maximumLength(int* nums, int n, int k)
{
    int dp[k][k];
    int ans=0;
    memset(dp,0,sizeof(dp));
    for(int m=0;m<n;m++)
    {
        nums[m]%=k;
        for(int i=0;i<k;i++)
        {
            dp[i][nums[m]]=dp[nums[m]][i]+1;
            ans=max(dp[i][nums[m]],ans);
        }
    }
    return ans;
}
