#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int minCostClimbingStairs(int* cost, int n)
{
    int dp[n];
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 0; i < n - 2; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + cost[i]);
        dp[i + 2] = min(dp[i + 2], dp[i] + cost[i]);
    }
    dp[n - 1] = min(dp[n - 1], dp[n - 2] + cost[n - 2]);
    return min(dp[n - 1] + cost[n - 1], dp[n - 2] + cost[n - 2]);
}
