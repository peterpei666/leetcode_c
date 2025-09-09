#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int peopleAwareOfSecret(int n, int delay, int forget)
{
    const int mod = 1e9 + 7;
    long long dp[n + 1];
    long long pre[n + 2];
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    dp[1] = 1;
    pre[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int l = max(0, i - forget);
        int r = max(0, i - delay);
        long long val = (pre[r] - pre[l] + mod) % mod;
        dp[i] = val;
        pre[i] = (pre[i - 1] + dp[i]) % mod;
    }
    long long ans = 0;
    for (int i = n - forget + 1; i <= n; i++)
    {
        if (i >= 1)
        {
            ans = (ans + dp[i]) % mod;
        }
    }
    return ans % mod;
}
