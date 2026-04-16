#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int maxRotateFunction(int* nums, int n)
{
    int total = 0, cur = 0;
    for (int i = 0; i < n; i++)
    {
        total += nums[i];
        cur += i * nums[i];
    }
    int ans = cur;
    for (int i = n - 1; i >= 0; i--)
    {
        cur = cur + total - n * nums[i];
        ans = max(ans, cur);
    }
    return ans;
}
