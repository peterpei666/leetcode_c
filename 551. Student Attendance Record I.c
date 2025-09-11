#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool checkRecord(char* s)
{
    int a = 0, l = 0;
    int n = (int)strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            l++;
            if (l == 3)
            {
                return false;
            }
        }
        else
        {
            l = 0;
        }
        if (s[i] == 'A')
        {
            a++;
        }
    }
    return a < 2;
}
