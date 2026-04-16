#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return (*(int**)p1)[1] - (*(int**)p2)[1];
}

int eraseOverlapIntervals(int** intervals, int n, int* intervalsColSize)
{
    qsort(intervals, n, sizeof(int*), cmp);
    int cnt = 0;
    int cur = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] < cur)
        {
            cnt++;
        }
        else
        {
            cur = intervals[i][1];
        }
    }
    return cnt;
}
