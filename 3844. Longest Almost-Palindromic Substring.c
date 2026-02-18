#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int find(int dp[2501][2501], int l, int r, char* s)
{
    if (l >= r)
    {
        return 0;
    }
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    if (s[l] == s[r])
    {
        dp[l][r] = find(dp, l + 1, r - 1, s);
    }
    else
    {
        dp[l][r] = 1 + min(find(dp, l + 1, r, s), find(dp, l, r - 1, s));
    }
    return dp[l][r];
}

int almostPalindromic(char* s)
{
    static int dp[2501][2501];
    memset(dp, -1, sizeof(dp));
    int n = (int)strlen(s);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + ans; j < n; j++)
        {
            if (find(dp, i, j, s) <= 1)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    return ans;
}
