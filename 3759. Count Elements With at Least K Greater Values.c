#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

int countElements(int* nums, int n, int k)
{
    qsort(nums, n, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j + 1 < n && nums[j + 1] == nums[i])
        {
            j++;
        }
        if (n - j - 1 >= k)
        {
            ans += j - i + 1;
        }
        i = j;
    }
    return ans;
}
