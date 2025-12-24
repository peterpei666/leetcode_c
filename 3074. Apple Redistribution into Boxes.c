#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p2 - *(int*)p1;
}

int minimumBoxes(int* apple, int n, int* capacity, int m)
{
    qsort(capacity, m, sizeof(int), cmp);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += apple[i];
    }
    int ans = 0;
    while (total > 0)
    {
        total -= capacity[ans];
        ans++;
    }
    return ans;
}
