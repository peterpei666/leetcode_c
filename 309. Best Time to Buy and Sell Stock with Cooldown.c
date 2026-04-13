#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int maxProfit(int* prices, int n)
{
    int dp[2][3];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[0][2] = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        int mask = i & 1;
        int prev = mask ^ 1;
        dp[mask][0] = max(dp[prev][0], dp[prev][2]);
        dp[mask][1] = max(dp[prev][0] - prices[i], dp[prev][1]);
        dp[mask][2] = dp[prev][1] + prices[i];
    }
    return max(dp[(n - 1) & 1][0], dp[(n - 1) & 1][2]);
}
