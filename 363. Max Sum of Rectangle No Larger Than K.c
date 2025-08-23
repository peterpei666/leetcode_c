#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int maxSumSubmatrix(int** matrix, int matrixSize, int* matrixColSize, int k)
{
    int m=matrixSize;
    int n=matrixColSize[0];
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]+matrix[i][j]-dp[i][j];
        }
    }
    int ans=INT_MIN;
    for(int x=m;x>=1;x--)
    {
        for(int y=n;y>=1;y--)
        {
            for(int i=x;i>=1;i--)
            {
                for(int j=y;j>=1;j--)
                {
                    int temp=dp[x][y]-dp[i-1][y]-dp[x][j-1]+dp[i-1][j-1];
                    if(temp<=k)
                    {
                        ans=max(ans,temp);
                    }
                }
            }
            if(ans==k)
            {
                return k;
            }
        }
    }
    return ans;
}
