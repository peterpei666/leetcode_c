#include <stdio.h>
#include <stdlib.h>

int alternatingSum(int* nums, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            ans -= nums[i];
        }
        else
        {
            ans += nums[i];
        }
    }
    return ans;
}
