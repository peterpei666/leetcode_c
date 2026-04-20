#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int deleteAndEarn(int* nums, int n)
{
    int cnt[10001] = {0};
    for (int i = 0; i < n; i++)
    {
        cnt[nums[i]]++;
    }
    int dp[10001][2] = {0};
    dp[1][0] = 0;
    dp[1][1] = cnt[1] * 1;
    for (int i = 2; i <= 10000; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + cnt[i] * i;
    }
    return max(dp[10000][0], dp[10000][1]);
}
