#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int* maxValue(int* nums, int n, int* returnSize)
{
    int prefix[n];
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], nums[i]);
    }
    int suffix[n];
    suffix[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = min(suffix[i + 1], nums[i]);
    }
    int* ans = (int*)malloc(sizeof(int) * n);
    ans[n - 1] = prefix[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (prefix[i] > suffix[i + 1])
        {
            ans[i] = ans[i + 1];
        }
        else
        {
            ans[i] = prefix[i];
        }
    }
    *returnSize = n;
    return ans;
}
