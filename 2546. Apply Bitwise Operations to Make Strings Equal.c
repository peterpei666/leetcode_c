#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool makeStringsEqual(char* s, char* target)
{
    int n = (int)strlen(s);
    bool a = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            a = false;
            break;
        }
    }
    bool b = true;
    for (int i = 0; i < n; i++)
    {
        if (target[i] == '1')
        {
            b = false;
            break;
        }
    }
    return !(a ^ b);
}
