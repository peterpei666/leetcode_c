#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long long max(long long a, long long b)
{
    return a > b ? a : b;
}

long long minTime(int* skill, int m, int* mana, int n)
{
    long long dp[5001];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[j + 1] = max(dp[j + 1], dp[j]) + 1LL * skill[j] * mana[i];
        }
        for (int j = m - 1; j >= 0; j--)
        {
            dp[j] = dp[j + 1] - 1LL * skill[j] * mana[i];
        }
    }
    return dp[m];
}
