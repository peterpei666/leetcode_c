#include <stdio.h>
#include <stdlib.h>

int longestSubsequence(int* nums, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= nums[i];
    }
    if (ans)
    {
        return n;
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            return n - 1;
        }
    }
    return 0;
}
