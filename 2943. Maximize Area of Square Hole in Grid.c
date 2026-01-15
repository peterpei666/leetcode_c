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
    return *(int*)p1 - *(int*)p2;
}

int maximizeSquareHoleArea(int n, int m, int* hBars, int hs, int* vBars, int vs)
{
    qsort(hBars, hs, sizeof(int), cmp);
    qsort(vBars, vs, sizeof(int), cmp);
    int h = 1, v = 1;
    int temp = 1;
    for (int i = 1; i < hs; i++)
    {
        if (hBars[i] == hBars[i - 1] + 1)
        {
            temp++;
        }
        else
        {
            temp = 1;
        }
        h = max(h, temp);
    }
    temp = 1;
    for (int i = 1; i < vs; i++)
    {
        if (vBars[i] == vBars[i - 1] + 1)
        {
            temp++;
        }
        else
        {
            temp = 1;
        }
        v = max(v, temp);
    }
    return (min(h, v) + 1) * (min(h, v) + 1);
}
