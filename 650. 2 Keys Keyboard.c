#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int minSteps(int n)
{
    int dp[n + 1];
    memset(dp, 0x7f, sizeof(dp));
    dp[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 2 * i; j <= n; j += i)
        {
            dp[j] = min(dp[j], dp[i] + j / i);
        }
    }
    return dp[n];
}
