#include <stdio.h>
#include <stdlib.h>

static inline int max(int a,int b)
{
    return a>b?a:b;
}

static inline int min(int a,int b)
{
    return a<b?a:b;
}

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize)
{
    int m=dungeonSize;
    int n=dungeonColSize[0];
    int dp[m][n];
    dp[m-1][n-1]=max(1,1-dungeon[m-1][n-1]);
    for(int i=m-2;i>=0;i--)
    {
        dp[i][n-1]=max(1,dp[i+1][n-1]-dungeon[i][n-1]);
    }
    for(int i=n-2;i>=0;i--)
    {
        dp[m-1][i]=max(1,dp[m-1][i+1]-dungeon[m-1][i]);
    }
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);
        }
    }
    return dp[0][0];
}
