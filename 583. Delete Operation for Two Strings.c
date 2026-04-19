#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int minDistance(char* w1, char* w2)
{
    int m = (int)strlen(w1);
    int n = (int)strlen(w2);
    int dp[2][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++)
    {
        int mask = i & 1;
        int prev = mask ^ 1;
        for (int j = 1; j <= n; j++)
        {
            if (w1[i - 1] == w2[j - 1])
            {
                dp[mask][j] = dp[prev][j - 1] + 1;
            }
            else
            {
                dp[mask][j] = max(dp[mask][j - 1], dp[prev][j]);
            }
        }
    }
    return m + n - 2 * dp[m & 1][n];
}
