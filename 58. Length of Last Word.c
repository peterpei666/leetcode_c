#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char* s)
{
    int i = (int)strlen(s) - 1;
    int ans = 0;
    while (i >= 0 && s[i] == ' ')
    {
        i--;
    }
    while (i >= 0 && s[i] != ' ')
    {
        i--;
        ans++;
    }
    return ans;
}
