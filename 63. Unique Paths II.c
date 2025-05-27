#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int m, int* obstacleGridColSize)
{
    int i,j;
    int n=obstacleGridColSize[0];
    if(obstacleGrid[0][0]||obstacleGrid[m-1][n-1])
    {
        return 0;
    }
    obstacleGrid[0][0]=1;
    for(i=1;i<m;i++)
    {
        if(obstacleGrid[i][0])
        {
            obstacleGrid[i][0]=0;
        }
        else
        {
            obstacleGrid[i][0]=obstacleGrid[i-1][0];
        }
    }
    for(i=1;i<n;i++)
    {
        if(obstacleGrid[0][i])
        {
            obstacleGrid[0][i]=0;
        }
        else
        {
            obstacleGrid[0][i]=obstacleGrid[0][i-1];
        }
    }
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(obstacleGrid[i][j])
            {
                obstacleGrid[i][j]=0;
            }
            else
            {
                obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
            }
        }
    }
    return obstacleGrid[m-1][n-1];
}
