#include <stdio.h>
#include <stdlib.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int getMinDistance(int* nums, int n, int target, int start)
{
    int ans = 10000;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            ans = min(ans, abs(i - start));
        }
    }
    return ans;
}
