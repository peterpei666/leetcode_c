#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int earliestFinishTime(int* ls, int landStartTimeSize, int* ld, int landDurationSize, int* ws, int waterStartTimeSize, int* wd, int waterDurationSize)
{
    int first;
    int n = landStartTimeSize;
    int m = waterStartTimeSize;
    int ans = INT_MAX;
    first = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        first = min(first, ls[i] + ld[i]);
    }
    for (int i = 0; i < m; i++)
    {
        ans = min(ans, max(first, ws[i]) + wd[i]);
    }
    first = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        first = min(first, ws[i] + wd[i]);
    }
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, max(first, ls[i]) + ld[i]);
    }
    return ans;
}
