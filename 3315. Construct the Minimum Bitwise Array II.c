#include <stdio.h>
#include <stdlib.h>

int* minBitwiseArray(int* nums, int n, int* returnSize)
{
    *returnSize = n;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 2)
        {
            nums[i] = -1;
        }
        else
        {
            for (int j = 0; j < 31; j++)
            {
                if ((nums[i] & (1 << j)) == 0)
                {
                    nums[i] -= 1 << (j - 1);
                    break;
                }
            }
        }
    }
    return nums;
}
