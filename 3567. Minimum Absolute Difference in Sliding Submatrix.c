#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int cmp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

int** minAbsDiff(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes)
{
    int m = gridSize;
    int n = gridColSize[0];
    int** ans = (int**)malloc(sizeof(int*) * (m - k + 1));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (m - k + 1));
    *returnSize = m - k + 1;
    for (int i = 0; i < m - k + 1; i++)
    {
        (*returnColumnSizes)[i] = n - k + 1;
        ans[i] = (int*)malloc(sizeof(int) * (n - k + 1));
        for (int j = 0; j < n - k + 1; j++)
        {
            int temp[k * k];
            int sz = 0;
            for (int x = i; x < i + k; x++)
            {
                for (int y = j; y < j + k; y++)
                {
                    temp[sz++] = grid[x][y];
                }
            }
            qsort(temp, k * k, sizeof(int), cmp);
            int t = temp[k * k - 1] - temp[0];
            for (sz = 1; sz < k * k && t; sz++)
            {
                t = min(t, temp[sz] == temp[sz - 1] ? INT_MAX : temp[sz] - temp[sz - 1]);
            }
            ans[i][j] = t;
        }
    }
    return ans;
}
