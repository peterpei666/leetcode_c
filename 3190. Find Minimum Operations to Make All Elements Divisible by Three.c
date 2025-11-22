#include <stdio.h>
#include <stdlib.h>

int minimumOperations(int* nums, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (nums[i] % 3 != 0);
    }
    return ans;
}
