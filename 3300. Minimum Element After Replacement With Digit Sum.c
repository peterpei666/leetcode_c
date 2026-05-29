#include <stdio.h>
#include <stdlib.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int minElement(int* nums, int n)
{
    int ans = 1000;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        while (nums[i])
        {
            temp += nums[i] % 10;
            nums[i] /= 10;
        }
        ans = min(ans, temp);
    }
    return ans;
}
