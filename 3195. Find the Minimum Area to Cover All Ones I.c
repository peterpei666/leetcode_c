#include <stdio.h>
#include <stdlib.h>

static inline int max(int a,int b)
{
    return a>b?a:b;
}

static inline int min(int a,int b)
{
    return a<b?a:b;
}

int minimumArea(int** grid, int gridSize, int* gridColSize)
{
    int m=gridSize;
    int n=gridColSize[0];
    int x1=-1,x2=-1;
    int y1=-1,y2=-1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
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
