#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char v[5] = {'a', 'e', 'i', 'o', 'u'};

inline bool is_vowel(char c)
{
    for (int i = 0; i < 5; i++)
    {
        if (c == v[i] || c - 'A' + 'a' == v[i])
        {
            return true;
        }
    }
    return false;
}

int cmp(const void* p1, const void* p2)
{
    return *(char*)p1 - *(char*)p2;
}

char* sortVowels(char* s)
{
    int k = 0;
    int n = (int)strlen(s);
    char vowel[100000];
    for (int i = 0; i < n; i++)
    {
        if (is_vowel(s[i]))
        {
            vowel[k] = s[i];
            s[i] = '*';
            k++;
        }
    }
    qsort(vowel, k, sizeof(char), cmp);
    for (int i = 0, j = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            s[i] = vowel[j];
            j++;
        }
    }
    return s;
}
