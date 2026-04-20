#include <stdio.h>
#include <stdlib.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int firstStableIndex(int* nums, int n, int k)
{
    int suf[n];
    suf[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = min(suf[i + 1], nums[i]);
    }
    int pre = nums[0];
    for (int i = 0; i < n; i++)
    {
        pre = max(pre, nums[i]);
        if (pre - suf[i] <= k)
        {
            return i;
        }
    }
    return -1;
}
