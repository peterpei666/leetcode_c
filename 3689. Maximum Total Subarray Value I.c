#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

long long maxTotalValue(int* nums, int n, int k)
{
    int a = INT_MAX;
    int b = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        a = min(a, nums[i]);
        b = max(b, nums[i]);
    }
    return 1LL * (b - a) * k;
}
