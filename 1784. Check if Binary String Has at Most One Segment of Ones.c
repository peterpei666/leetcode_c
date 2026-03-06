#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool checkOnesSegment(char* s)
{
    int ans = 0;
    int n = (int)strlen(s);
    for (int i = 1; i < n; i++)
    {
        ans += abs(s[i] - s[i - 1]);
    }
    return ans == 0 || ans == 1;
}
