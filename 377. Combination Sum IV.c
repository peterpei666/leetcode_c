#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int combinationSum4(int* nums, int n, int target)
{
    long long dp[1001] = {0};
    const int mod = INT_MAX;
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (i - nums[k] >= 0)
            {
                dp[i] = (dp[i] + dp[i - nums[k]]) & mod;
            }
        }
    }
    return (int)dp[target];
}
