#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize)
{
    int i,j,ans=0,small;
    int m=gridSize;
    int n=gridColSize[0];
    int x[m][n];
    int y[m][n];
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(grid[i][j])
            {
                x[i][j]=j==0?1:x[i][j-1]+1;
                y[i][j]=i==0?1:y[i-1][j]+1;
            }
        }
    }
    for(i=m-1;i>=0;i--)
    {
        for(j=n-1;j>=0;j--)
        {
            small=min(x[i][j],y[i][j]);
            while(small>ans)
            {
                if(x[i-small+1][j]>=small&&y[i][j-small+1]>=small)
                {
                    ans=small;
                }
                small--;
            }
        }
    }
    return ans*ans;
}
