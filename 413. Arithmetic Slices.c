#include <stdio.h>
#include <stdlib.h>

int numberOfArithmeticSlices(int* nums, int n)
{
    int ans = 0;
    for (int i = 2, len = 0; i < n; i++)
    {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
        {
            len++;
        }
        else
        {
            len = 0;
        }
        ans += len;
    }
    return ans;
}
