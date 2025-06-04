#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize)
{
    int i,j,cnt=0;
    int m=gridSize;
    int n=gridColSize[0];
    int x[m+1][n+1];
    int y[m+1][n+1];
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            x[i][j]=x[i-1][j]+x[i][j-1]-x[i-1][j-1];
            y[i][j]=y[i-1][j]+y[i][j-1]-y[i-1][j-1];
            if(grid[i-1][j-1]=='X')
            {
                x[i][j]++;
            }
            if(grid[i-1][j-1]=='Y')
            {
                y[i][j]++;
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i][j]==y[i][j]&&x[i][j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}
