#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int minOperations(char* s)
{
    int n = (int)strlen(s);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (26 + 'a' - s[i]) % 26);
    }
    return ans;
}
