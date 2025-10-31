#include <stdio.h>
#include <stdlib.h>

int** subsets(int* nums, int n, int* returnSize, int** returnColumnSizes)
{
    int** ans = (int**)malloc(sizeof(int*) * (1 << n));
    *returnSize = 1 << n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (1 << n));
    for (int mask = 0; mask < (1 << n); mask++)
    {
        (*returnColumnSizes)[mask] = __builtin_popcount(mask);
        int* temp = (int*)malloc(sizeof(int) * (*returnColumnSizes)[mask]);
        for (int i = 0, j = 0; i < n; i++)
        {
            if ((1 << i) & mask)
            {
                temp[j] = nums[i];
                j++;
            }
        }
        ans[mask] = temp;
    }
    return ans;
}
