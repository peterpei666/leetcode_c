#include <stdio.h>
#include <stdlib.h>

int minOperations(int* nums, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            return 1;
        }
    }
    return 0;
}
