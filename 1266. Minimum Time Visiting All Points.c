#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int minTimeToVisitAllPoints(int** points, int n, int* pointsColSize)
{
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
    }
    return ans;
}
