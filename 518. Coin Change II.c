#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int change(int amount, int* coins, int n)
{
    long long dp[5001] = {0};
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            if (dp[j] > INT_MAX)
            {
                break;
            }
            dp[j] += dp[j - coins[i]];
        }
    }
    return (int)dp[amount];
}
