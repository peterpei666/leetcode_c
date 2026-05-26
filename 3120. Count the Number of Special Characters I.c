#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfSpecialChars(char* word)
{
    int n = (int)strlen(word);
    int upper = 0;
    int lower = 0;
    for (int i = 0; i < n; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            upper |= 1 << (word[i] - 'A');
        }
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            lower |= 1 << (word[i] - 'a');
        }
    }
    return __builtin_popcount(upper & lower);
}
