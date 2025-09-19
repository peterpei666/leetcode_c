#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int one(char c)
{
    if (c == '0') return 0;
    return 1;
}

static inline int two(char c1, char c2)
{
    if (c1 == '1') return 1;
    if (c1 == '2') return c2 < '7' ? 1 : 0;
    return 0;
}

int numDecodings(char* s)
{
    int n = (int)strlen(s);
    const int mod = 1e9 + 7;
    int dp[3] = {0};
    dp[(n - 1) % 3] = one(s[n - 1]);
    if (n > 1)
    {
        dp[(n - 2) % 3] = one(s[n - 2]) * dp[(n - 1) % 3] + two(s[n - 2], s[n - 1]);
        for (int i = n - 3; i >= 0; i--)
        {
            dp[i % 3] = one(s[i]) * dp[(i + 1) % 3] + two(s[i], s[i + 1]) * dp[(i + 2) % 3];
        }
    }
    return dp[0];
}
