#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isIsomorphic(char* s, char* t)
{
    char mp[128] = {0};
    int n = (int)strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (mp[s[i]] == 0)
        {
            mp[s[i]] = t[i];
        }
        if (mp[s[i]] != t[i])
        {
            return false;
        }
    }
    bool found[128] = {false};
    for (int i = 0; i < 127; i++)
    {
        if (mp[i] && found[mp[i]])
        {
            return false;
        }
        found[mp[i]] = true;
    }
    return true;
}
