#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int mini(int a,int b)
{
    return a<b?a:b;
}

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int remove_num(int pre,int idx,int* nums,int n,int dp[n+1][n+1])
{
    if(idx==n)
    {
        return nums[pre];
    }
    if(idx==n-1)
    {
        return maxi(nums[pre],nums[idx]);
    }
    if(dp[pre][idx]!=-1)
    {
        return dp[pre][idx];
    }
    int c1,c2,c3;
    c1=maxi(nums[pre],nums[idx])+remove_num(idx+1,idx+2,nums,n,dp);
    c2=maxi(nums[pre],nums[idx+1])+remove_num(idx,idx+2,nums,n,dp);
    c3=maxi(nums[idx],nums[idx+1])+remove_num(pre,idx+2,nums,n,dp);
    dp[pre][idx]=mini(c1,mini(c2,c3));
    return dp[pre][idx];
}

int minCost(int* nums, int n)
{
    int dp[n+1][n+1];
    memset(dp,-1,sizeof(dp));
    return remove_num(0,1,nums,n,dp);
}
