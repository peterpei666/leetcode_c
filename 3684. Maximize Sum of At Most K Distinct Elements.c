#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p2 - *(int*)p1;
}

int* maxKDistinct(int* nums, int n, int k, int* returnSize)
{
    qsort(nums, n, sizeof(int), cmp);
    int i = 1;
    int* ans = (int*)malloc(sizeof(int) * k);
    ans[0] = nums[0];
    for (int j = 1; j < n && i < k; j++)
    {
        if (nums[j] != nums[j - 1])
        {
            ans[i] = nums[j];
            i++;
        }
    }
    *returnSize = i;
    return ans;
}
