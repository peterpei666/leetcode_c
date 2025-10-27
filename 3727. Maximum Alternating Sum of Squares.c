#include <stdio.h>
#include <stdlib.h>

inline int abs(int a)
{
    return a < 0 ? -a : a;
}

int cmp(const void* p1, const void* p2)
{
    return *(int*)p2 - *(int*)p1;
}

long long maxAlternatingSum(int* nums, int n)
{
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        nums[i] = abs(nums[i]);
    }
    qsort(nums, n, sizeof(int), cmp);
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        ans += 1LL * nums[i] * nums[i];
    }
    for (int i = (n + 1) / 2; i < n; i++)
    {
        ans -= 1LL * nums[i] * nums[i];
    }
    return ans;
}
