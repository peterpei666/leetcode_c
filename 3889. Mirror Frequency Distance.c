#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mirror(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 'z' - (c - 'a');
    }
    return '9' - (c - '0');
}

int mirrorFrequency(char* s)
{
    int n = (int)strlen(s);
    int mp[128] = {0};
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        ans += abs(mp[c] - mp[mirror(c)]);
    }
    for (char c = '0'; c <= '9'; c++)
    {
        ans += abs(mp[c] - mp[mirror(c)]);
    }
    return ans / 2;
}
