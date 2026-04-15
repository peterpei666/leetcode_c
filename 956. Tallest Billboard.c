#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int tallestBillboard(int* rods, int n)
{
    int T = 0;
    for (int i = 0; i < n; i++)
    {
        T += rods[i];
    }
    int dp[2][T + 1];
    memset(dp, 0x80, sizeof(dp));
    dp[0][0] = 0;
    dp[0][rods[0]] = rods[0];
    for (int i = 1; i < n; i++)
    {
        int mask = i & 1;
        int prev = mask ^ 1;
        memcpy(dp[mask], dp[prev], sizeof(dp[mask]));
        for (int d = 0; d < T - rods[i]; d++)
        {
            dp[mask][d] = max(dp[mask][d], dp[prev][d + rods[i]] + rods[i]);
            dp[mask][d] = max(dp[mask][d], dp[prev][abs(d - rods[i])] + rods[i]);
        }
    }
    if (dp[(n - 1) & 1][0] < 0)
    {
        return 0;
    }
    return dp[(n - 1) & 1][0] / 2;
}
