#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

int dfs(int p,int* arr,int dp[],int n,int d)
{
    if(dp[p])
    {
        return dp[p];
    }
    int i;
    dp[p]=1;
    for(i=p-1;i>=max(0,p-d)&&arr[i]<arr[p];i--)
    {
        dp[p]=max(dp[p],1+dfs(i,arr,dp,n,d));
    }
    for(i=p+1;i<=min(n-1,p+d)&&arr[i]<arr[p];i++)
    {
        dp[p]=max(dp[p],1+dfs(i,arr,dp,n,d));
    }
    return dp[p];
}

int maxJumps(int* arr, int n, int d)
{
    int ret=0;
    int dp[n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        ret=max(ret,dfs(i,arr,dp,n,d));
    }
    return ret;
}
