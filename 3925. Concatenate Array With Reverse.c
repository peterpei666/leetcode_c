#include <stdio.h>
#include <stdlib.h>

int* concatWithReverse(int* nums, int n, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * 2 * n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = nums[i];
        ans[2 * n - i - 1] = nums[i];
    }
    *returnSize = 2 * n;
    return ans;
}
