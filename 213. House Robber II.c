#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int rob(int* nums, int n)
{
    int dp[2][2];
    dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = nums[0];
    for (int i = 2; i < n - 1; i++)
    {
        dp[i & 1][0] = max(dp[(i & 1) ^ 1][0], dp[(i & 1) ^ 1][1]);
        dp[i & 1][1] = dp[(i & 1) ^ 1][0] + nums[i];
    }
    int ans = max(dp[n & 1][0], dp[n & 1][1]);
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i & 1][0] = max(dp[(i & 1) ^ 1][0], dp[(i & 1) ^ 1][1]);
        dp[i & 1][1] = dp[(i & 1) ^ 1][0] + nums[i];
    }
    ans = max(ans, max(dp[(n & 1) ^ 1][0], dp[(n & 1) ^ 1][1]));
    return ans;
}
