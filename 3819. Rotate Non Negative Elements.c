#include <stdio.h>
#include <stdlib.h>

int* rotateElements(int* nums, int n, int k, int* returnSize)
{
    *returnSize = n;
    int pos[n];
    int sz = 0;
    for (int i = 0; i < n; i++)
    {
        if(nums[i] >= 0)
        {
            pos[sz] = nums[i];
            sz++;
        }
    }
    if (sz == 0)
    {
        return nums;
    }
    for (int i = 0, j = 0; i < n; i++)
    {
        if (nums[i] >= 0)
        {
            nums[i] = pos[(j + k) % sz];
            j++;
        }
    }
    return nums;
}
