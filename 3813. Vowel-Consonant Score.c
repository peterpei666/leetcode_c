#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vowelConsonantScore(char* s)
{
    int n = (int)strlen(s);
    int v = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            v++;
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            c++;
        }
    }
    if (c == 0)
    {
        return 0;
    }
    return v / c;
}
