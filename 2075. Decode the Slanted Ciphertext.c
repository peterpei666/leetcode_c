#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

char* decodeCiphertext(char* encodedText, int m)
{
    int n = (int)strlen(encodedText) / m;
    char* ans = (char*)malloc(m * n + 1);
    int sz = 0;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < min(m, n - i); k++)
        {
            int idx = i + k * n + k;
            ans[sz] = encodedText[idx];
            sz++;
        }
    }
    while (sz > 0 && ans[sz - 1] == ' ')
    {
        sz--;
    }
    ans[sz] = '\0';
    return ans;
}
