#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findTargetSumWays(int* nums, int n, int target)
{
    const int bias = 1000;
    int dp[2][2001] = {0};
    dp[0][nums[0] + bias]++;
    dp[0][-nums[0] + bias]++;
    int total = nums[0];
    for (int i = 1; i < n; i++)
    {
        int mask = i & 1;
        int prev = mask ^ 1;
        memset(dp[mask], 0, sizeof(dp[0]));
        for (int j = -total + bias; j <= total + bias; j++)
        {
            dp[mask][j + nums[i]] += dp[prev][j];
            dp[mask][j - nums[i]] += dp[prev][j];
        }
        total += nums[i];
    }
    return dp[(n - 1) & 1][target + bias];
}
