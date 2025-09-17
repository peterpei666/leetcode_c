#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

bool* subsequenceSumAfterCapping(int* nums, int n, int k, int* returnSize)
{
    qsort(nums, n, sizeof(int), cmp);
    bool sum[k + 1];
    memset(sum, false, sizeof(sum));
    sum[0] = true;
    bool* ans = (bool*)calloc(sizeof(bool), n);
    for (int i = 0, x = 1; x <= n; x++)
    {
        while (i < n && nums[i] < x)
        {
            for (int j = k; j >= nums[i]; j--)
            {
                if (sum[j - nums[i]])
                {
                    sum[j] = true;
                }
            }
            i++;
        }
        int bigger = n - i;
        for (int j = 0; j <= bigger && j * x <= k; j++)
        {
            if (sum[k - j * x])
            {
                ans[x - 1] = true;
                break;
            }
        }
    }
    *returnSize = n;
    return ans;
}
