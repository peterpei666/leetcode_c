#include <stdio.h>
#include <stdlib.h>

#define INF 10000000

void insert(int** edges, int edgesSize,int** board)
{
    int i;
    for(i=0;i<edgesSize;i++)
    {
        board[edges[i][0]][edges[i][1]]=edges[i][2];
        board[edges[i][1]][edges[i][0]]=edges[i][2];
    }
}

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold)
{
    int i,j,k,min,minc,count=0;
    int** board=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        board[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                board[i][j]=0;
            }
            else
            {
                board[i][j]=INF;
            }
        }
    }
    insert(edges,edgesSize,board);
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(board[i][k]<INF&&board[k][j]<INF&&board[i][j]>board[i][k]+board[k][j])
                {
                    board[i][j]=board[i][k]+board[k][j];
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(board[0][i]<=distanceThreshold)
        {
            count++;
        }
    }
    min=count;
    minc=0;
    for(i=1;i<n;i++)
    {
        count=0;
        for(j=0;j<n;j++)
        {
            if(board[i][j]<=distanceThreshold)
            {
                count++;
            }
        }
        if(count<=min)
        {
            min=count;
            minc=i;
        }
    }
    for(i=0;i<n;i++)
    {
        free(board[i]);
    }
    free(board);
    return minc;
}
