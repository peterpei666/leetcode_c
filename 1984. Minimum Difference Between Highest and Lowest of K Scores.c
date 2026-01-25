#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int minimumDifference(int* nums, int n, int k)
{
    qsort(nums, n, sizeof(int), cmp);
    int ans = 100000;
    for (int i = 0; i + k - 1 < n; i++)
    {
        ans = min(ans, nums[i + k - 1] - nums[i]);
    }
    return ans;
}
