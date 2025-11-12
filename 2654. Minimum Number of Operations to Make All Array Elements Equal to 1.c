#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static inline int gcd(int a, int b)
{
    while (b)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int minOperations(int* nums, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
        }
    }
    if (cnt)
    {
        return n - cnt;
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int cur = nums[i];
        int j = i + 1;
        while (j < n && cur != 1)
        {
            cur = gcd(cur, nums[j]);
            j++;
        }
        if (cur == 1)
        {
            ans = min(ans, j - i);
        }
    }
    if (ans == INT_MAX)
    {
        return -1;
    }
    return n + ans - 2;
}
