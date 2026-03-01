#include <stdio.h>
#include <stdlib.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int cmp(const void* p1, const void* p2)
{
    return  *(int*)p1 - *(int*)p2;
}

int arrayPairSum(int* nums, int n)
{
    int ans = 0;
    qsort(nums, n, sizeof(int), cmp);
    for (int i = 0; i < n; i += 2)
    {
        ans += min(nums[i], nums[i + 1]);
    }
    return ans;
}
