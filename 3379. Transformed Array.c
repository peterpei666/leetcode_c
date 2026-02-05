#include <stdio.h>
#include <stdlib.h>

int* constructTransformedArray(int* nums, int n, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = nums[((i + nums[i]) % n + n) % n];
    }
    *returnSize = n;
    return ans;
}
