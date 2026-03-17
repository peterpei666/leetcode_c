#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p2 - *(int*)p1;
}

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize)
{
    int m = matrixSize;
    int n = matrixColSize[0];
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        qsort(matrix[i], n, sizeof(int), cmp);
        for (int j = 0; j < n && matrix[i][j] > 0; j++)
        {
            ans = max(ans, matrix[i][j] * (j + 1));
        }
    }
    return ans;
}
