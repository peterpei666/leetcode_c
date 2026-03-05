#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int minOperations(char* s)
{
    int n = (int)strlen(s);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        ans1 += (s[i] - '0') ^ (i & 1);
        ans2 += (s[i] - '0') ^ (i & 1) ^ 1;
    }
    return min(ans1, ans2);
}
