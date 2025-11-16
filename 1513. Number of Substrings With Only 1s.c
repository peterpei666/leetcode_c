#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numSub(char* s)
{
    int n = (int)strlen(s);
    int ans = 0, cnt = 0;
    const int mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            ans = (ans + 1LL * cnt * (cnt + 1) / 2) % mod;
            cnt = 0;
        }
        else
        {
            cnt++;
        }
    }
    return (ans + 1LL * cnt * (cnt + 1) / 2) % mod;
}
