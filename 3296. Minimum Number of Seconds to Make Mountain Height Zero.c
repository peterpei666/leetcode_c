#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

inline long long get(long long x, long long t)
{
    return (sqrt(8 * (x / t) + 1) - 1) / 2;
}

bool check(long long x, int* workerTimes, int n, int mountainHeight)
{
    long long cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += get(x, workerTimes[i]);
        if (cur >= mountainHeight)
        {
            return true;
        }
    }
    return false;
}

long long minNumberOfSeconds(int mountainHeight, int* workerTimes, int n)
{
    long long l = 0, r = 1e18;
    long long ans = -1;
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (check(mid, workerTimes, n, mountainHeight))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
