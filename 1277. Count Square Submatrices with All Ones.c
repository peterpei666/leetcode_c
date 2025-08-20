#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int min(int a,int b)
{
    return a<b?a:b;
}

int countSquares(int** matrix, int matrixSize, int* matrixColSize)
{
    int m=matrixSize;
    int n=matrixColSize[0];
    int dp[2][n];
    int ans=0;
    for(int i=0;i<m;i++)
    {
        memset(dp[i%2],0,sizeof(dp[0]));
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j])
            {
                if(i*j)
                {
                    dp[i%2][j]=min(min(dp[(i-1)%2][j],dp[i%2][j-1]),dp[(i-1)%2][j-1])+1;
                }
                else
                {
                    dp[i%2][j]=1;
                }
                ans+=dp[i%2][j];
            }
        }
    }
    return ans;
}
