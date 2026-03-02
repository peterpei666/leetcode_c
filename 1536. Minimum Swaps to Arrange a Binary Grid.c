#include <stdio.h>
#include <stdlib.h>

static inline void swap(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int minSwaps(int** grid, int gridSize, int* gridColSize)
{
    int n = gridSize;
    int arr[200];
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < n && grid[i][n - 1 - j] == 0)
        {
            j++;
        }
        arr[i] = j;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < n - i - 1)
        {
            int p = -1;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] >= n - i - 1)
                {
                    p = j;
                    break;
                }
            }
            if (p == -1)
            {
                return -1;
            }
            for (int k = p; k > i; k--)
            {
                swap(&arr[k], &arr[k - 1]);
                ans++;
            }
        }
    }
    return ans;
}
