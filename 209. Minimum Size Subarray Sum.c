#include <stdio.h>
#include <stdlib.h>

int minSubArrayLen(int target, int* nums, int n)
{
    int ans = 1000000;
    for (int i = 0, j = -1, cur = 0; i < n; i++)
    {
        cur += nums[i];
        while (j + 1 < i && cur - nums[j + 1] >= target)
        {
            cur -= nums[j + 1];
            j++;
        }
        if (cur >= target)
        {
            ans = ans < i - j ? ans : i - j;
        }
    }
    return ans == 1000000 ? 0 : ans;
}
