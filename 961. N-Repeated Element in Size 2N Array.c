#include <stdio.h>
#include <stdlib.h>

int repeatedNTimes(int* nums, int n)
{
    int cnt[10001] = {0};
    for (int i = 0; i < n; i++)
    {
        cnt[nums[i]]++;
    }
    for (int i = 0; i < 10001; i++)
    {
        if (cnt[i] == n / 2)
        {
            return i;
        }
    }
    return -1;
}
