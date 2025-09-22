#include <stdio.h>
#include <stdlib.h>

int maxFrequencyElements(int* nums, int n)
{
    int cnt[101] = {0};
    for (int i = 0; i < n; i++)
    {
        cnt[nums[i]]++;
    }
    int ans = 0, temp = 0;
    for (int i = 0; i < 101; i++)
    {
        if (cnt[i] > temp)
        {
            ans = 0;
            temp = cnt[i];
        }
        if (cnt[i] == temp)
        {
            ans += temp;
        }
    }
    return ans;
}
