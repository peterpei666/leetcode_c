#include <stdio.h>
#include <stdlib.h>

int* leftRightDifference(int* nums, int n, int* returnSize)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += nums[i];
    }
    int left = 0;
    int* ans = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = abs(total - 2 * left - nums[i]);
        left += nums[i];
    }
    *returnSize = n;
    return ans;
}
