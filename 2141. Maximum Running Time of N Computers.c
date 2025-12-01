#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

long long maxRunTime(int n, int* batteries, int m)
{
    qsort(batteries, m, sizeof(int), cmp);
    long long extra = 0;
    for (int i = n; i < m; i++)
    {
        extra += batteries[i];
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (extra >= (batteries[i - 1] - batteries[i]) * 1LL * (n - i))
        {
            extra -= (batteries[i - 1] - batteries[i]) * 1LL * (n - i);
        }
        else
        {
            return batteries[i] * 1LL + extra / (n - i);
        }
    }
    return batteries[0] * 1LL + extra / n;
}
