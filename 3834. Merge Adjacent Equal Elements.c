#include <stdio.h>
#include <stdlib.h>

long long* mergeAdjacent(int* nums, int n, int* returnSize)
{
    long long* ans = (long long*)malloc(n * sizeof(long long));
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        long long temp = nums[i];
        while (idx && ans[idx - 1] == temp)
        {
            temp <<= 1;
            idx--;
        }
        ans[idx++] = temp;
    }
    *returnSize = idx;
    return ans;
}
