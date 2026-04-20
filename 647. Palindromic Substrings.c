#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count(char* s, int l, int r, int n)
{
    int ans = 0;
    while (l >= 0 && r < n && s[l] == s[r])
    {
        ans++;
        l--;
        r++;
    }
    return ans;
}

int countSubstrings(char* s)
{
    int n = (int)strlen(s);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += count(s, i, i, n) + count(s, i, i + 1, n);
    }
    return ans;
}
