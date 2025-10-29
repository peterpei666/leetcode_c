#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int maxSubArray(int* nums, int n)
{
    int ans = INT_MIN, temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += nums[i];
        ans = max(ans, temp);
        temp = max(0, temp);
    }
    return ans;
}
