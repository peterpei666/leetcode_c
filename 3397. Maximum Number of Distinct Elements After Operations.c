#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int cmp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

int maxDistinctElements(int* nums, int n, int k)
{
    qsort(nums, n, sizeof(int), cmp);
    int temp = INT_MIN;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (temp < nums[i] + k)
        {
            temp = max(temp + 1, nums[i] - k);
            ans++;
        }
    }
    return ans;
}
