#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

static inline int count(int* nums, int n, int mid)
{
    int cnt = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n && nums[j] - nums[i] <= mid)
        {
            j++;
        }
        cnt += j - i - 1;
    }
    return cnt;
}

int smallestDistancePair(int* nums, int n, int k)
{
    qsort(nums, n, sizeof(int), cmp);
    int l = 0, r = nums[n - 1] - nums[0];
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (count(nums, n, mid) < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}
