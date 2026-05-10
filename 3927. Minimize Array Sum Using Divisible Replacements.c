#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

long long minArraySum(int* nums, int n)
{
    int cnt[100005] = {0};
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        m = max(m, nums[i]);
        cnt[nums[i]]++;
    }
    long long ans = 0;
    for (int x = 0; x <= m; x++)
    {
        if (cnt[x])
        {
            for (int t = x; t <= m + 1; t += x)
            {
                if (cnt[t])
                {
                    ans += 1LL * cnt[t] * x;
                    cnt[t] = 0;
                }
            }
        }
    }
    return ans;
}
