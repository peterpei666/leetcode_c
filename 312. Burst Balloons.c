#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int memo[501][501];

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int dfs(int arr[],int i,int j,int n)
{
    if(i>j)
    {
        return 0;
    }
    if(memo[i][j]!=-1)
    {
        return memo[i][j];
    }
    if(i==j)
    {
        int temp=arr[i];
        if(i-1>=0)
        {
            temp*=arr[i-1];
        }
        if(i+1<n)
        {
            temp*=arr[i+1];
        }
        memo[i][j]=temp;
        return temp;
    }
    int ans=0;
    for(int k=i;k<=j;k++)
    {
        int temp=arr[k];
        if(j+1<=n)
        {
            temp*=arr[j+1];
        }
        if(i-1>=0)
        {
            temp*=arr[i-1];
        }
        temp+=dfs(arr,i,k-1,n)+dfs(arr,k+1,j,n);
        ans=max(ans,temp);
    }
    memo[i][j]=ans;
    return ans;
}

int maxCoins(int* nums, int n)
{
    n+=2;
    memset(memo,-1,sizeof(memo));
    int arr[n];
    arr[0]=1;
    arr[n-1]=1;
    memcpy(arr+1,&nums[0],sizeof(int)*(n-2));
    return dfs(arr,1,n-2,n);
}
