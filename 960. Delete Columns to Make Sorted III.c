#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int minDeletionSize(char** strs, int n)
{
    int dp[100];
    int m = (int)strlen(strs[0]);
    for (int i = 0; i < m; i++)
    {
        dp[i] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            bool f = true;
            for (int k = 0; k < n; k++)
            {
                if (strs[k][j] > strs[k][i])
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, dp[i]);
    }
    return m - ans;
}
