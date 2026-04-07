#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

static inline long long min(long long a, long long b)
{
    return a < b ? a : b;
}

int get(int* nums, int i)
{
    return max(0, max(nums[i - 1], nums[i + 1]) + 1 - nums[i]);
}

long long minIncrease(int* nums, int n)
{
    if (n & 1)
    {
        long long ans = 0;
        for (int i = 1; i < n; i += 2)
        {
            ans += get(nums, i);
        }
        return ans;
    }
    long long cur = 0;
    for (int i = 2; i < n - 1; i += 2)
    {
        cur += get(nums, i);
    }
    long long ans = cur;
    for (int i = 1; i < n - 1; i += 2)
    {
        cur += get(nums, i) - get(nums, i + 1);
        ans = min(ans, cur);
    }
    return ans;
}
