#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkValidGrid(int** grid, int gridSize, int* gridColSize)
{
    if(grid[0][0])
    {
        return false;
    }
    uint8_t arr[49];
    uint8_t i,j;
    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<gridSize;j++)
        {
            arr[grid[i][j]]=i*7+j;
        }
    }
    for(i=1;i<gridSize*gridSize;i++)
    {
        if(abs(arr[i]%7-arr[i-1]%7)*abs(arr[i]/7-arr[i-1]/7)!=2)
        {
            return false;
        }
    }
    return true;
}
