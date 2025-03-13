#include <stdio.h>
#include <stdlib.h>

int direction[4][2]={-1,0,1,0,0,-1,0,1};

void dfs(char** grid,int gridSize,int* gridColSize,int x,int y)
{
    if(x<0||x>=gridSize||y<0||y>=gridColSize[x]||grid[x][y]=='0')
    {
        return;
    }
    grid[x][y]='0';
    int d,row,col;
    for(d=0;d<4;d++)
    {
        row=x+direction[d][0];
        col=y+direction[d][1];
        dfs(grid,gridSize,gridColSize,row,col);
    }
}

int numIslands(char** grid,int gridSize,int* gridColSize)
{
    int i,j,count=0;
    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<gridColSize[i];j++)
        {
            if(grid[i][j]=='1')
            {
                dfs(grid,gridSize,gridColSize,i,j);
                count++;
            }
        }
    }
    return count;
}
