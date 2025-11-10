#include <stdio.h>
#include <stdlib.h>

int stk[100000];

int check(int* nums, int l, int r)
{
    int k = 0;
    int ans = 0;
    for (int i = l; i < r; i++)
    {
        while (k && stk[k - 1] > nums[i])
        {
            k--;
            ans++;
        }
        while (k && stk[k - 1] == nums[i])
        {
            k--;
        }
        stk[k] = nums[i];
        k++;
    }
    return ans + k;
}

int minOperations(int* nums, int n)
{
    int ans = 0;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            ans += check(nums, l, i);
            l = i + 1;
        }
    }
    ans += check(nums, l, n);
    return ans;
}
