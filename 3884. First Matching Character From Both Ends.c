#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int firstMatchingIndex(char* s)
{
    int n = (int)strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[n - i - 1])
        {
            return i;
        }
    }
    return -1;
}
