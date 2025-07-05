#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long dp[101][101][101];

static inline long long min(long long a,long long b)
{
    return a<b?a:b;
}

long long dfs(int* nums,int idx,int n,int k,int op1,int op2)
{
    if(idx==n)
    {
        return 0;
    }
    if(dp[idx][op1][op2]!=-1)
    {
        return dp[idx][op1][op2];
    }
    long long ans=nums[idx]+dfs(nums,idx+1,n,k,op1,op2);
    if(op1>0)
    {
        ans=min(ans,(nums[idx]+1)/2+dfs(nums,idx+1,n,k,op1-1,op2));
    }
    if(op2>0&&nums[idx]>=k)
    {
        ans=min(ans,nums[idx]-k+dfs(nums,idx+1,n,k,op1,op2-1));
    }
    if(op1>0&&op2>0&&nums[idx]>=k)
    {
        ans=min(ans,(nums[idx]-k+1)/2+dfs(nums,idx+1,n,k,op1-1,op2-1));
    }
    if(op1>0&&op2>0&&(nums[idx]+1)/2>=k)
    {
        ans=min(ans,(nums[idx]+1)/2-k+dfs(nums,idx+1,n,k,op1-1,op2-1));
    }
    dp[idx][op1][op2]=ans;
    return ans;
}

int minArraySum(int* nums,int n,int k,int op1,int op2)
{
    memset(dp,-1,sizeof(dp));
    return (int)dfs(nums,0,n,k,op1,op2);
}
