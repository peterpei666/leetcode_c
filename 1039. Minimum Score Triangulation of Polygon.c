#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

int minScoreTriangulation(int* values, int n)
{
    int i,j,k;
    int dp[50][50]={0};
    for(i=n-1;i>=0;i--)
    {
        for(j=i+1;j<n;j++)
        {
            for(k=i+1;k<j;k++)
            {
                dp[i][j]=min(dp[i][j]==0?INT_MAX:dp[i][j],dp[i][k]+values[i]*values[j]*values[k]+dp[k][j]);
            }
        }
    }
    return dp[0][n-1];
}
