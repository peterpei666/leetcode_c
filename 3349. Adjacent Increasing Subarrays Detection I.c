#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check(int* nums, int idx, int k)
{
    for (int i = idx + 1; i < idx + k; i++)
    {
        if (nums[i] <= nums[i - 1])
        {
            return false;
        }
    }
    return true;
}

bool hasIncreasingSubarrays(int* nums, int n, int k)
{
    for (int i = 0; i <= n - 2 * k; i++)
    {
        if (check(nums, i, k) && check(nums, i + k, k))
        {
            return true;
        }
    }
    return false;
}
