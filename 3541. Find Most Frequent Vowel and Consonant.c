#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int maxFreqSum(char* s)
{
    int n = (int)strlen(s);
    int cnt[26] = {0};
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a']++;
    }
    char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
    int t1 = 0, t2 = 0;
    for (int i = 0; i < 26; i++)
    {
        bool v = false;
        for (int j = 0; j < 5; j++)
        {
            if (i == vowel[j] - 'a')
            {
                v = true;
                break;
            }
        }
        if (v)
        {
            t1 = max(t1, cnt[i]);
        }
        else
        {
            t2 = max(t2, cnt[i]);
        }
    }
    return t1 + t2;
}
