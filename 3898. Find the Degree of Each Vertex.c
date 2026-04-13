#include <stdio.h>
#include <stdlib.h>

int* findDegrees(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int n = matrixSize;
    int* ans = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i] += matrix[i][j];
        }
    }
    *returnSize = n;
    return ans;
}
