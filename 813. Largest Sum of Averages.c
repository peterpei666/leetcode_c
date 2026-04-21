#include <stdio.h>
#include <stdlib.h>

static inline double max(double a, double b)
{
    return a > b ? a : b;
}

double largestSumOfAverages(int* nums, int n, int k)
{
    double dp[2][n];
    int prefix[n + 1];
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        dp[1][i] = (prefix[n] - prefix[i]) / 1.0 / (n - i);
    }
    for (int group = 2; group <= k; group++)
    {
        int mask = group & 1;
        int prev = mask ^ 1;
        for (int i = 0; i < n; i++)
        {
            dp[mask][i] = 0.0;
        }
        for (int l = 0; l + group <= n; l++)
        {
            for (int r = l; r + group <= n; r++)
            {
                dp[mask][l] = max(dp[mask][l], dp[prev][r + 1] + (prefix[r + 1] - prefix[l]) / 1.0 / (r - l + 1));
            }
        }
    }
    return dp[k & 1][0];
}
