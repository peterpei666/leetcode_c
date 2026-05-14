#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

bool isGood(int* nums, int n)
{
    qsort(nums, n, sizeof(int), cmp);
    n--;
    if (nums[0] != 1)
    {
        return false;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i + 1] != nums[i] + 1)
        {
            return false;
        }
    }
    return nums[n] == n;
}
