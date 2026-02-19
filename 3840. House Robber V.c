#include <stdio.h>
#include <stdlib.h>

static inline long long max(long long a, long long b)
{
    return a > b ? a : b;
}

long long rob(int* nums, int n, int* colors, int colorsSize)
{
    long long dp[2][2] = {0};
    dp[0][0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (colors[i] != colors[i - 1])
        {
            dp[i & 1][0] = max(dp[(i - 1) & 1][0], dp[(i - 1) & 1][1]) + nums[i];
        }
        else
        {
            dp[i & 1][0] = dp[(i - 1) & 1][1] + nums[i];
        }
        dp[i & 1][1] = max(dp[(i - 1) & 1][0], dp[(i - 1) & 1][1]);
    }
    return max(dp[(n - 1) & 1][0], dp[(n - 1) & 1][1]);
}
