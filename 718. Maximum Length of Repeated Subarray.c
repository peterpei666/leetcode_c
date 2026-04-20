#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int findLength(int* nums1, int m, int* nums2, int n)
{
    int dp[2][n + 1];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        int mask = i & 1;
        int prev = mask ^ 1;
        memset(dp[mask], 0, sizeof(dp[0]));
        for (int j = n - 1; j >= 0; j--)
        {
            if (nums1[i] == nums2[j])
            {
                dp[mask][j] = dp[prev][j + 1] + 1;
                ans = max(ans, dp[mask][j]);
            }
            else
            {
                dp[mask][j] = 0;
            }
        }
    }
    return ans;
}
