#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

int absDifference(int* nums, int n, int k)
{
    qsort(nums, n, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += nums[n - i - 1] - nums[i];
    }
    return ans;
}
