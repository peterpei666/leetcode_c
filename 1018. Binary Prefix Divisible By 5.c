#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool* prefixesDivBy5(int* nums, int n, int* returnSize)
{
    bool* ans = (bool*)malloc(sizeof(bool) * n);
    *returnSize = n;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = ((temp << 1) + nums[i]) % 5;
        ans[i] = !temp;
    }
    return ans;
}
