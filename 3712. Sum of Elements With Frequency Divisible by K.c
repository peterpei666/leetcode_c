#include <stdio.h>
#include <stdlib.h>

int sumDivisibleByK(int* nums, int n, int k)
{
    int cnt[101] = {0};
    for (int i = 0; i < n; i++)
    {
        cnt[nums[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (cnt[i] && cnt[i] % k == 0)
        {
            ans += i * cnt[i];
        }
    }
    return ans;
}
