#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

static inline int dis(int a, int b)
{
    return abs(a % 6 - b % 6) + abs(a / 6 - b / 6);
}

int minimumDistance(char* word)
{
    int n = (int)strlen(word);
    int dp[2][26][26] = {0};
    for (int i = 0; i < n; i++)
    {
        int mask = i & 1;
        int next = mask ^ 1;
        int t = word[i] - 'A';
        memset(dp[next], 0x7f, sizeof(dp[0]));
        for (int a = 0; a < 26; a++)
        {
            for (int b = 0; b < 26; b++)
            {
                dp[next][a][t] = min(dp[next][a][t], dp[mask][a][b] + dis(b, t));
                dp[next][t][b] = min(dp[next][t][b], dp[mask][a][b] + dis(a, t));
            }
        }
    }
    int ans = INT_MAX;
    int mask = n & 1;
    for (int a = 0; a < 26; a++)
    {
        for (int b = 0; b < 26; b++)
        {
            ans = min(ans, dp[mask][a][b]);
        }
    }
    return ans;
}
