#include <stdio.h>
#include <stdlib.h>

int countStableSubsequences(int* nums, int n)
{
    const int mod = 1e9 + 7;
    long long dp[2][2] = {0};
    for (int i = 0; i < n; i++)
    {
        if (nums[i] & 1)
        {
            dp[0][1] = (dp[0][1] + dp[0][0]) % mod;
            dp[0][0] = (dp[0][0] + dp[1][0] + dp[1][1] + 1) % mod;
        }
        else
        {
            dp[1][1] = (dp[1][1] + dp[1][0]) % mod;
            dp[1][0] = (dp[1][0] + dp[0][0] + dp[0][1] + 1) % mod;
        }
    }
    return (dp[0][0] + dp[0][1] + dp[1][0] + dp[1][1]) % mod;
}
