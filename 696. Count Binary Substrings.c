#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int countBinarySubstrings(char* s)
{
    int n = (int)strlen(s);
    int stk[100000];
    int sz = 1;
    stk[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            stk[sz - 1]++;
        }
        else
        {
            stk[sz++] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i < sz; i++)
    {
        ans += min(stk[i - 1], stk[i]);
    }
    return ans;
}
