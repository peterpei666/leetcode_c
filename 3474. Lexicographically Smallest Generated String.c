#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* generateString(char* str1, char* str2)
{
    int m = (int)strlen(str1);
    int n = (int)strlen(str2);
    char* ans = (char*)malloc(m + n);
    ans[m + n - 1] = '\0';
    memset(ans, '?', m + n - 1);
    for (int i = 0; i < m; i++)
    {
        if (str1[i] == 'F')
        {
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (ans[i + j] != '?' && ans[i + j] != str2[j])
            {
                ans[0] = '\0';
                return ans;
            }
            ans[i + j] = str2[j];
        }
    }
    char* old = ans;
    ans = (char*)malloc(m + n);
    strcpy(ans, old);
    for (int i = 0; i < m + n - 1; i++)
    {
        if (ans[i] == '?')
        {
            ans[i] = 'a';
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (str1[i] == 'T' || strncmp(ans + i, str2, n))
        {
            continue;
        }
        bool valid = false;
        for (int j = i + n - 1; j >= i; j--)
        {
            if (old[j] == '?')
            {
                ans[j] = 'b';
                valid = true;
                break;
            }
        }
        if (!valid)
        {
            ans[0] = '\0';
            return ans;
        }
    }
    return ans;
}
