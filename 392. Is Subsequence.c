#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t)
{
    int m = (int)strlen(s);
    int n = (int)strlen(t);
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (s[i] == t[j])
        {
            i++;
        }
        j++;
    }
    return i == m;
}
