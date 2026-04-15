#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int find(int dp[201][201], int l, int r)
{
    if (l >= r)
    {
        return 0;
    }
    if (dp[l][r] != 0x7f7f7f7f)
    {
        return dp[l][r];
    }
    for (int i = l; i <= r; i++)
    {
        dp[l][r] = min(dp[l][r], max(find(dp, l, i - 1), find(dp, i + 1, r)) + i);
    }
    return dp[l][r];
}

int getMoneyAmount(int n)
{
    int dp[201][201];
    memset(dp, 0x7f, sizeof(dp));
    return find(dp, 1, n);
}
