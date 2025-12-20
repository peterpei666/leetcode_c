#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int minDeletionSize(char** strs, int n)
{
    int ans = 0;
    for (int i = 0; strs[0][i] != '\0'; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (strs[j][i] < strs[j - 1][i])
            {
                ans++;
                break;
            }
        }
    }
    return ans;
}
