#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int longestAlternating(int* nums, int n)
{
    int lu[n];
    int ld[n];
    lu[0] = 1;
    ld[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            lu[i] = ld[i - 1] + 1;
            ld[i] = 1;
        }
        else if (nums[i] < nums[i - 1])
        {
            ld[i] = lu[i - 1] + 1;
            lu[i] = 1;
        }
        else
        {
            lu[i] = 1;
            ld[i] = 1;
        }
    }
    int ru[n];
    int rd[n];
    ru[n - 1] = 1;
    rd[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ru[i] = rd[i + 1] + 1;
            rd[i] = 1;
        }
        else if (nums[i] > nums[i + 1])
        {
            rd[i] = ru[i + 1] + 1;
            ru[i] = 1;
        }
        else
        {
            ru[i] = 1;
            rd[i] = 1;
        }
    }
    int ans = max(lu[n - 1], ld[n - 1]);
    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i - 1] < nums[i + 1])
        {
            ans = max(ans, ld[i - 1] + rd[i + 1]);
        }
        else if (nums[i - 1] > nums[i + 1])
        {
            ans = max(ans, lu[i - 1] + ru[i + 1]);
        }
        ans = max(ans, max(lu[i], ld[i]));
    }
    return ans;
}
