#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(char* s)
{
    char t[200000];
    int i = 0, k = 0;
    while(s[i] != '\0')
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            t[k] = s[i] - 'A' + 'a';
            k++;
        }
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            t[k] = s[i];
            k++;
        }
        i++;
    }
    int l = 0, r = k - 1;
    while (l < r)
    {
        if (t[l] != t[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
