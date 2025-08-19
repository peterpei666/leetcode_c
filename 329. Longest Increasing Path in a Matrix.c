#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int dir[4][2]={-1,0,0,-1,0,1,1,0};

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int dfs(int m,int n,int memo[m][n],int** matrix,int i,int j)
{
    if(memo[i][j]) return memo[i][j];
    memo[i][j]=1;
    for(int d=0;d<4;d++)
    {
        int x=i+dir[d][0];
        int y=j+dir[d][1];
        if(x>=0&&x<m&&y>=0&&y<n&&matrix[i][j]<matrix[x][y])
        {
            memo[i][j]=max(memo[i][j],dfs(m,n,memo,matrix,x,y)+1);
        }
    }
    return memo[i][j];
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize)
{
    int m=matrixSize;
    int n=matrixColSize[0];
    int memo[m][n];
    memset(memo,0,sizeof(memo));
    int ans=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans=max(ans,dfs(m,n,memo,matrix,i,j));
        }
    }
    return ans;
}
