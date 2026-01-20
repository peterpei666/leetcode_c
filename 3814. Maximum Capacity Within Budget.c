#include <stdio.h>
#include <stdlib.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int cmp(const void* p1, const void* p2)
{
    return *(long long*)p1 - *(long long*)p2 > 0 ? 1 : -1;
}

int maxCapacity(int* costs, int n, int* capacity, int capacitySize, int budget)
{
    long long t[n];
    for (int i = 0; i < n; i++)
    {
        t[i] = (long long)costs[i] << 32 | capacity[i];
    }
    qsort(t, n, sizeof(long long), cmp);
    int pre[n];
    for (int i = 0, m = 0; i < n; i++)
    {
        m = max(m, (int)t[i]);
        pre[i] = m;
    }
    int ans = 0;
    for (int i = 0, j = n - 1; i < n; i++)
    {
        int c = (int)(t[i] >> 32);
        int v = (int)t[i];
        if (c < budget)
        {
            ans = max(ans, v);
        }
        while (j >= 0 && (t[j] >> 32) + c >= budget)
        {
            j--;
        }
        int k = min(i - 1, j);
        if (k >= 0)
        {
            ans = max(ans, v + pre[k]);
        }
    }
    return ans;
}
