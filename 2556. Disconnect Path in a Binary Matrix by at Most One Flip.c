#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int m,n;

bool dfs(int** grid,int x,int y)
{
    if(x==m-1&&y==n-1)
    {
        return true;
    }
    if(x>=m||y>=n||grid[x][y]==0)
    {
        return false;
    }
    grid[x][y]=0;
    return dfs(grid,x+1,y)||dfs(grid,x,y+1);
}

bool isPossibleToCutPath(int** grid, int gridSize, int* gridColSize)
{
    m=gridSize;
    n=gridColSize[0];
    if(dfs(grid,0,0)==false)
    {
        return true;
    }
    grid[0][0]=1;
    if(dfs(grid,0,0)==false)
    {
        return true;
    }
    return false;
}
