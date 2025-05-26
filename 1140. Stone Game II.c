#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int stoneGameII(int* piles, int n)
{
    int i,j,k;
    int suffix[n];
    int dp[n][n+1];
    suffix[n-1]=piles[n-1];
    for(i=n-2;i>=0;i--)
    {
        suffix[i]=suffix[i+1]+piles[i];
    }
    memset(dp,0,sizeof(dp));
    for(i=n-1;i>=0;i--)
    {
        for(j=1;j<=n;j++)
        {
            if(i+2*j>=n)
            {
                dp[i][j]=suffix[i];
            }
            else
            {
                for(k=1;k<=2*j;k++)
                {
                    dp[i][j]=max(dp[i][j],suffix[i]-dp[i+k][max(k,j)]);
                }
            }
        }
    }
    return dp[0][1];
}
