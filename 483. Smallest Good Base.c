#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

long long cal(long long base, int k)
{
    long long ans = 1;
    long long cur = 1;
    for (int i = 1; i < k; i++)
    {
        if (cur > LLONG_MAX / base)
        {
            return LLONG_MAX;
        }
        cur *= base;
        if (ans > LLONG_MAX - cur)
        {
            return LLONG_MAX;
        }
        ans += cur;
    }
    return ans;
}

char* smallestGoodBase(char* n)
{
    long long m = atoll(n);
    int k = 0;
    while (m)
    {
        m /= 2;
        k++;
    }
    m = atoll(n);
    for (int i = k; i >= 2; i--)
    {
        long long l = 2;
        long long r = ceil(pow(m, 1.0 / (i - 1))) + 1;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            long long sum = cal(mid, i);
            if (sum == m)
            {
                char* s = (char*)malloc(20);
                sprintf(s, "%lld", mid);
                return s;
            }
            else if (sum < m)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    char* s = (char*)malloc(20);
    sprintf(s, "%lld", m - 1);
    return s;
}
