#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int orderOfLargestPlusSign(int n, int** mines, int m, int* minesColSize)
{
    bool mp[n][n];
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < m; i++)
    {
        mp[mines[i][0]][mines[i][1]] = true;
    }
    int ans[n][n];
    memset(ans, 0x1, sizeof(ans));
    for (int i = 0; i < n; i++)
    {
        int cur;
        cur = 0;
        for (int j = 0; j < n; j++)
        {
            if (mp[i][j])
            {
                cur = 0;
            }
            else
            {
                cur++;
            }
            ans[i][j] = min(ans[i][j], cur);
        }
        cur = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (mp[i][j])
            {
                cur = 0;
            }
            else
            {
                cur++;
            }
            ans[i][j] = min(ans[i][j], cur);
        }
    }
    for (int j = 0; j < n; j++)
    {
        int cur;
        cur = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp[i][j])
            {
                cur = 0;
            }
            else
            {
                cur++;
            }
            ans[i][j] = min(ans[i][j], cur);
        }
        cur = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (mp[i][j])
            {
                cur = 0;
            }
            else
            {
                cur++;
            }
            ans[i][j] = min(ans[i][j], cur);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res = max(res, ans[i][j]);
        }
    }
    return res;
}
