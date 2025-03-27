#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int directions[4][2]={-1,0,1,0,0,-1,0,1};

void dfs(int** grid,int x,int y,int id,int n)
{
    if(x<0||y<0||x>=n||y>=n||grid[x][y]!=1)
    {
        return;
    }
    int nx,ny,i;
    grid[x][y]=id;
    for(i=0;i<4;i++)
    {
        nx=x+directions[i][0];
        ny=y+directions[i][1];
        dfs(grid,nx,ny,id,n);
    }
}

int largestIsland(int** grid, int gridSize, int* gridColSize)
{
    bool f=true;  //no 0
    int i,j,d,id=2,max=0,nx,ny,temp;
    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<gridColSize[i];j++)
        {
            if(grid[i][j]==1)
            {
                dfs(grid,i,j,id,gridSize);
                id++;
            }
            if(f&&grid[i][j]==0)
            {
                f=false;
            }
        }
    }
    if(f)
    {
        return gridSize*gridSize;
    }
    int* size=(int*)calloc(id,sizeof(int));
    bool* visited=(bool*)malloc(id*sizeof(int));
    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<gridColSize[i];j++)
        {
            if(grid[i][j])
            {
                size[grid[i][j]]++;
            }
        }
    }
    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<gridColSize[i];j++)
        {
            if(grid[i][j]==0)
            {
                memset(visited,false,id);
                temp=1;
                for(d=0;d<4;d++)
                {
                    nx=i+directions[d][0];
                    ny=j+directions[d][1];
                    if(nx>=0&&ny>=0&&nx<gridSize&&ny<gridColSize[nx]&&visited[grid[nx][ny]]==false)
                    {
                        temp+=size[grid[nx][ny]];
                        visited[grid[nx][ny]]=true;
                    }
                }
                if(temp>max)
                {
                    max=temp;
                }
            }
        }
    }
    free(visited);
    free(size);
    return max;
}
