#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p2 - *(int*)p1;
}

int minimumCost(int* cost, int n)
{
    qsort(cost, n, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 3 != 2)
        {
            ans += cost[i];
        }
    }
    return ans;
}
