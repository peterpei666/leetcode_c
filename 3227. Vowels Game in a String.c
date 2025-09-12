#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool doesAliceWin(char* s)
{
    int n = (int)strlen(s);
    static char vowel[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (s[i] == vowel[j])
            {
                return true;
            }
        }
    }
    return false;
}
