#include <stdio.h>
#include <stdlib.h>

int sortPermutation(int* nums, int n)
{
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i)
        {
            ans &= nums[i];
        }
    }
    return ans == -1 ? 0 : ans;
}
