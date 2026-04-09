#include <stdio.h>
#include <stdlib.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int minAbsoluteDifference(int* nums, int n)
{
    int ans = 1000;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 1)
        {
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == 2)
            {
                ans = min(ans, abs(i - j));
            }
        }
    }
    return ans == 1000 ? -1 : ans;
}
