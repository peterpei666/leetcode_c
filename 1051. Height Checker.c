#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p1, const void* p2)
{
    return  *(int*)p1 - *(int*)p2;
}

int heightChecker(int* heights, int n)
{
    int temp[100];
    memcpy(temp, heights, sizeof(int) * n);
    qsort(temp, n, sizeof(n), cmp);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (heights[i] != temp[i])
        {
            ans++;
        }
    }
    return ans;
}
