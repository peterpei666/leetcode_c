#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

int largestPerimeter(int* nums, int n)
{
    qsort(nums, n, sizeof(int), cmp);
    for (int i = n - 1; i >= 2; i--)
    {
        if (nums[i - 2] + nums[i - 1] > nums[i])
        {
            return nums[i - 2] + nums[i - 1] + nums[i];
        }
    }
    return 0;
}
