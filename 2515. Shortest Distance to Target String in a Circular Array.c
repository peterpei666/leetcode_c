#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int closestTarget(char** words, int n, char* target, int startIndex)
{
    int ans = 1000;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(words[i], target) == 0)
        {
            ans = min(ans, min(abs(i - startIndex), n - abs(i - startIndex)));
        }
    }
    return ans == 1000 ? -1 : ans;
}
