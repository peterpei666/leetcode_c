#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int minFlips(char* s)
{
    int n = (int)strlen(s);
    int cur0 = 0, cur1 = 0;
    for (int i = 0; i < n; i++)
    {
        cur0 += (s[i] - '0') ^ (i & 1);
        cur1 += (s[i] - '0') ^ (i & 1) ^ 1;
    }
    int ans = min(cur0, cur1);
    for (int i = n; i < 2 * n; i++)
    {
        cur0 += (s[i % n] - '0') ^ (i & 1);
        cur1 += (s[i % n] - '0') ^ (i & 1) ^ 1;
        cur0 -= (s[i % n] - '0') ^ ((i - n) & 1);
        cur1 -= (s[i % n] - '0') ^ ((i - n) & 1) ^ 1;
        ans = min(ans, min(cur0, cur1));
    }
    return ans;
}
