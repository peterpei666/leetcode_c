#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    int x,y,dx,dy,cnt,temp;
    int** graph=(int**)malloc(sizeof(int*)*n);
    *returnSize=n;
    *returnColumnSizes=(int*)malloc(sizeof(int)*n);
    for(x=0;x<n;x++)
    {
        graph[x]=(int*)calloc(n,sizeof(int));
        (*returnColumnSizes)[x]=n;
    }
    x=0;
    y=0;
    dx=0;
    dy=1;
    cnt=1;
    while(cnt<=n*n)
    {
        graph[x][y]=cnt;
        if(x+dx<0||x+dx>=n||y+dy<0||y+dy>=n||graph[x+dx][y+dy])
        {
            temp=dx;
            dx=dy;
            dy=-temp;
        }
        x+=dx;
        y+=dy;
        cnt++;
    }
    return graph;
}
