#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int canBeTypedWords(char* text, char* brokenLetters)
{
    int mp = 0;
    int n = (int)strlen(brokenLetters);
    for (int i = 0; i < n; i++)
    {
        mp |= 1 << (brokenLetters[i] - 'a');
    }
    n = (int)strlen(text);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int valid = 1;
        while (i < n && text[i] != ' ')
        {
            if (mp & (1 << (text[i] - 'a')))
            {
                valid = 0;
            }
            i++;
        }
        ans += valid;
    }
    return ans;
}
