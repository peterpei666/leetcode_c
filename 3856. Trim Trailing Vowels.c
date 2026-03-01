#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static inline bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char* trimTrailingVowels(char* s)
{
    int n = (int)strlen(s) - 1;
    while (n >= 0 && isVowel(s[n]))
    {
        n--;
    }
    s[n + 1] = '\0';
    return s;
}
