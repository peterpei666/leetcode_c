#include <stdio.h>
#include <stdlib.h>

inline int abs(int a)
{
    return a < 0 ? -a : a;
}

int countValidSelections(int* nums, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    int temp = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        temp += nums[i];
        if (nums[i] == 0)
        {
            if (abs(2 * temp - sum) == 1)
            {
                ans++;
            }
            else if (2 * temp == sum)
            {
                ans += 2;
            }
        }
    }
    return ans;
}
