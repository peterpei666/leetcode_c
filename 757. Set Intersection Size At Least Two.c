#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    int* a = *((int**)p1);
    int* b = *((int**)p2);
    return a[1] == b[1] ? -a[0] + b[0] : a[1] - b[1];
}

int intersectionSizeTwo(int** intervals, int n, int* intervalsColSize)
{
    int sz = 0;
    qsort(intervals, n, sizeof(int*), cmp);
    int list[6000];
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < sz && cnt < 2; j++)
        {
            if (list[j] <= intervals[i][1] && list[j] >= intervals[i][0])
            {
                cnt++;
            }
        }
        for (int j = intervals[i][1]; cnt < 2; j--)
        {
            list[sz] = j;
            sz++;
            cnt++;
        }
    }
    return sz;
}
