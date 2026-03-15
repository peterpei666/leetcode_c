#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int titleToNumber(char* columnTitle)
{
    int n = (int)strlen(columnTitle);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans * 26 + (columnTitle[i] - 'A' + 1);
    }
    return ans;
}
