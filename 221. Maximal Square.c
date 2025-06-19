#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

inline int min(int a,int b)
{
    return a<b?a:b;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
    int i,j,len=0;
    int m=matrixSize;
    int n=matrixColSize[0];
    int dp[m][n];
    memset(dp,0,sizeof(dp));
    for(i=0;i<m;i++)
    {
        dp[i][0]=matrix[i][0]-'0';
        len=max(len,dp[i][0]);
    }
    for(i=1;i<n;i++)
    {
        dp[0][i]=matrix[0][i]-'0';
        len=max(len,dp[0][i]);
    }
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(matrix[i][j]=='1')
            {
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                len=max(dp[i][j],len);
            }
        }
    }
    return len*len;
}
