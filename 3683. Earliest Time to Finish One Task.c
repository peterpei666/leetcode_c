#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int earliestTime(int** tasks, int n, int* tasksColSize)
{
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, tasks[i][0] + tasks[i][1]);
    }
    return ans;
}
