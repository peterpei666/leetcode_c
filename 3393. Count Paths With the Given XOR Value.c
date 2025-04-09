#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int dp[300][300][16];

int f(int** grid,int gridSize,int* gridColSize,int k,int i,int j,int cur)
{
    if(i>=gridSize||j>=gridColSize[i])
    {
        return 0;
    }
    int r,d;
    cur^=grid[i][j];
    if(i==gridSize-1&&j==gridColSize[i]-1)
    {
        return cur==k;
    }
    if(dp[i][j][cur]!=-1)
    {
        return dp[i][j][cur];
    }
    r=f(grid,gridSize,gridColSize,k,i,j+1,cur);
    d=f(grid,gridSize,gridColSize,k,i+1,j,cur);
    dp[i][j][cur]=(r+d)%MOD;
    return dp[i][j][cur];
}

int countPathsWithXorValue(int** grid, int gridSize, int* gridColSize, int k)
{
    int i,j,m;
    for(i=0;i<300;i++)
    {
        for(j=0;j<300;j++)
        {
            for(m=0;m<16;m++)
            {
                dp[i][j][m]=-1;
            }
        }
    }
    return f(grid,gridSize,gridColSize,k,0,0,0);
}
