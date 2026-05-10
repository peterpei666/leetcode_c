#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int maximumJumps(int* nums, int n, int target)
{
    int dp[1000];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] != -1 && abs(nums[i] - nums[j]) <= target)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n - 1];
}
