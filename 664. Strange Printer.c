#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int dfs(int memo[100][100], int l, int r, char* s)
{
    if (l > r)
    {
        return 0;
    }
    if (memo[l][r] != -1)
    {
        return memo[l][r];
    }
    int ans = 1 + dfs(memo, l + 1, r, s);
    for (int i = l + 1; i <= r; i++)
    {
        if (s[l] == s[i])
        {
            ans = min(ans, dfs(memo, l, i - 1, s) + dfs(memo, i + 1, r, s));
        }
    }
    memo[l][r] = ans;
    return ans;
}

int strangePrinter(char* s)
{
    int n = (int)strlen(s);
    int k = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            s[k] = s[i];
            k++;
        }
    }
    s[k] = '\0';
    int memo[100][100];
    memset(memo, -1, sizeof(memo));
    return dfs(memo, 0, k - 1, s);
}
