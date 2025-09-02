#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long min(long long a, long long b)
{
    return a < b ? a : b;
}

long long minArraySum(int* nums, int n, int k)
{
    long long dp[k];
    memset(dp, 0x7f, sizeof(dp));
    long long sum = 0;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        dp[sum % k] = min(dp[sum % k], sum);
        sum = dp[sum % k];
    }
    return sum;
}
