#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int i,j;
    int m=matrixSize;
    int n=matrixColSize[0];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]>target)
            {
                break;
            }
            if(matrix[i][j]==target)
            {
                return true;
            }
        }
    }
    return false;
}
