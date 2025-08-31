#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int maxi(int a, int b)
{
    return a > b ? a : b;
}

static inline long long maxll(long long a, long long b)
{
    return a > b ? a : b;
}

long long maxProduct(int* nums, int n)
{
    int temp = nums[0];
    for (int i = 1; i < n; i++)
    {
        temp = maxi(temp, nums[i]);
    }
    int wid = 0;
    while (temp)
    {
        wid++;
        temp /= 2;
    }
    int mask = 1 << wid;
    int dp[mask];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        dp[nums[i]] = nums[i];
    }
    for (int i = 0; i < mask; i++)
    {
        if (dp[i])
        {
            continue;
        }
        for (int j = 0; j < wid; j++)
        {
            if (i & (1 << j))
            {
                dp[i] = maxi(dp[i], dp[i ^ (1 << j)]);
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = maxll(ans, (long long)nums[i] * dp[(mask - 1) ^ nums[i]]);
    }
    return ans;
}
