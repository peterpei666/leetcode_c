#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

inline int mini(int a,int b)
{
    return a<b?a:b;
}

int mergeStones(int* stones, int n, int k)
{
    if((n-1)%(k-1))
    {
        return -1;
    }
    int i,j,m,mid;
    int prefix[n];
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    prefix[0]=stones[0];
    for(i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]+stones[i];
    }
    for(m=k;m<=n;m++)
    {
        for(i=0;i<=n-m;i++)
        {
            j=i+m-1;
            dp[i][j]=INT_MAX;
            for(mid=i;mid<j;mid+=k-1)
            {
                dp[i][j]=mini(dp[i][j],dp[i][mid]+dp[mid+1][j]);
            }
            if((j-i)%(k-1)==0)
            {
                if(i-1>=0)
                {
                    dp[i][j]+=prefix[j]-prefix[i-1];
                }
                else
                {
                    dp[i][j]+=prefix[j];
                }
            }
        }
    }
    return dp[0][n-1];
}

