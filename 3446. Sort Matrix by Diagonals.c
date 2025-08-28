#include <stdio.h>
#include <stdlib.h>

int cmp1(const void* p1, const void* p2)
{
    return *(int*)p2 - *(int*)p1;
}

int cmp2(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

int** sortMatrix(int** grid, int n, int* gridColSize, int* returnSize, int** returnColumnSizes)
{
    int temp[10];
    int k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i + j < n; j++)
        {
            temp[j] = grid[i + j][j];
        }
        qsort(temp, n - i, sizeof(int), cmp1);
        for (int j = 0; i + j < n; j++)
        {
            grid[i + j][j] = temp[j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; i + j < n; j++)
        {
            temp[j] = grid[j][i + j];
        }
        qsort(temp, n - i, sizeof(int), cmp2);
        for (int j = 0; i + j < n; j++)
        {
            grid[j][i + j] = temp[j];
        }
    }
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        (*returnColumnSizes)[i] = n;
    }
    return grid;
}
