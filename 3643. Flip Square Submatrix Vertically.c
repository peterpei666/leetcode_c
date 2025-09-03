#include <stdio.h>
#include <stdlib.h>

static inline void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y, int k, int* returnSize, int** returnColumnSizes)
{
    for (int i = y; i < y + k; i++)
    {
        int l = x, r = x + k - 1;
        while (l < r)
        {
            swap(&grid[l][i], &grid[r][i]);
            l++;
            r--;
        }
    }
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    return grid;
}
