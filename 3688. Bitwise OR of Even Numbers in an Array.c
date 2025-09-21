#include <stdio.h>
#include <stdlib.h>

int evenNumberBitwiseORs(int* nums, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 == 0)
        {
            ans |= nums[i];
        }
    }
    return ans;
}
