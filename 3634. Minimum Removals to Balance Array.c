#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int minRemoval(int* nums, int n, int k)
{
    qsort(nums, n, sizeof(int), cmp);
    int l = 0, r = n - 1;
    while (r >= 0 && nums[r] > 1LL * nums[l] * k)
    {
        r--;
    }
    int ans = r - l + 1;
    for (; r < n - 1; l++)
    {
        while (r < n && nums[r] <= 1LL * nums[l] * k)
        {
            r++;
        }
        ans = max(ans, r - l);
    }
    return n - ans;
}
