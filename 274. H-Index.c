#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p2 - *(int*)p1;
}

int hIndex(int* citations, int n)
{
    qsort(citations, n, sizeof(int), cmp);
    int ans = citations[0];
    for (int i = 0; ans > i; ans--)
    {
        while (i < n && citations[i] >= ans)
        {
            i++;
        }
        if (ans <= i)
        {
            break;
        }
    }
    return ans;
}
