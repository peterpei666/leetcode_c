#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize)
{
    int i,j;
    int m=gridSize;
    int n=gridColSize[0];
    long long row[m];
    long long col[n];
    long long sum=0;
    long long temp;
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            row[i]+=grid[i][j];
            col[j]+=grid[i][j];
        }
    }
    for(i=0;i<m;i++)
    {
        sum+=row[i];
    }
    if(sum%2)
    {
        return false;
    }
    temp=0;
    for(i=0;i<m-1;i++)
    {
        temp+=row[i];
        if(temp==sum/2)
        {
            return true;
        }
    }
    temp=0;
    for(i=0;i<n-1;i++)
    {
        temp+=col[i];
        if(temp==sum/2)
        {
            return true;
        }
    }
    return false;
}
