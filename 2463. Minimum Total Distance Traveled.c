#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline long long min(long long a, long long b)
{
    return a < b ? a : b;
}

int cmp1(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

int cmp2(const void* p1, const void* p2)
{
    return (*(int**)p1)[0] - (*(int**)p2)[0];
}

long long minimumTotalDistance(int* robot, int n, int** factory, int m, int* factoryColSize)
{
    long long dp[101][101];
    memset(dp, 0x7f, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    qsort(robot, n, sizeof(int), cmp1);
    qsort(factory, m, sizeof(int*), cmp2);
    for (int j = 1; j <= m; j++)
    {
        int p = factory[j - 1][0];
        int limit = factory[j - 1][1];
        for (int i = 0; i <= n; i++)
        {
            dp[i][j] = dp[i][j - 1];
            long long dis = 0;
            for (int k = 1; k <= limit && i - k >= 0; k++)
            {
                dis += abs(robot[i - k] - p);
                dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + dis);
            }
        }
    }
    return dp[n][m];
}
