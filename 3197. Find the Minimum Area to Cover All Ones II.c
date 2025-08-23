#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int max(int a,int b)
{
    return a>b?a:b;
}

static inline int min(int a,int b)
{
    return a<b?a:b;
}

int count(int m,int n,int grid[m][n],int l,int r,int u,int d)
{
    int x1=-1,x2=-1;
    int y1=-1,y2=-1;
    for(int i=l;i<=r;i++)
    {
        for(int j=u;j<=d;j++)
        {
            if(grid[i][j])
            {
                if(x1==-1&&y1==-1)
                {
                    x1=i;
                    y1=j;
                }
                x1=min(x1,i);
                x2=max(x2,i);
                y1=min(y1,j);
                y2=max(y2,j);
            }
        }
    }
    if(x1!=-1)
    {
        return (x2-x1+1)*(y2-y1+1);
    }
    return 0;
}

int solve(int m,int n,int grid[m][n])
{
    int ans=m*n;
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            ans=min(ans,count(m,n,grid,0,i,0,n-1)+count(m,n,grid,i+1,m-1,0,j)+count(m,n,grid,i+1,m-1,j+1,n-1));
            ans=min(ans,count(m,n,grid,0,i,0,j)+count(m,n,grid,0,i,j+1,n-1)+count(m,n,grid,i+1,m-1,0,n-1));
        }
    }
    for(int i=0;i<m-2;i++)
    {
        for(int j=i+1;j<m-1;j++)
        {
            ans=min(ans,count(m,n,grid,0,i,0,n-1)+count(m,n,grid,i+1,j,0,n-1)+count(m,n,grid,j+1,m-1,0,n-1));
        }
    }
    return ans;
}

int minimumSum(int** grid, int gridSize, int* gridColSize)
{
    int m=gridSize;
    int n=gridColSize[0];
    int mat1[m][n];
    for(int i=0;i<m;i++)
    {
        memcpy(mat1[i],grid[i],sizeof(int)*n);
    }
    int mat2[n][m];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat2[j][i]=mat1[i][j];
        }
    }
    return min(solve(m,n,mat1),solve(n,m,mat2));
}
