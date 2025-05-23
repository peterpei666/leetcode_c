#include <stdio.h>
#include <stdlib.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int rob(int* nums, int n)
{
    if(n==1)
    {
        return nums[0];
    }
    if(n==2)
    {
        return maxi(nums[0],nums[1]);
    }
    int i;
    int dp[3];
    dp[0]=nums[0];
    dp[1]=maxi(nums[0],nums[1]);
    for(i=2;i<n;i++)
    {
        dp[i%3]=maxi(dp[(i-1)%3],dp[(i-2)%3]+nums[i]);
    }
    return dp[(n-1)%3];
}
