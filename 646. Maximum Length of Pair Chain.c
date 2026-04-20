#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int cmp(const void* p1, const void* p2)
{
    return (*(int**)p1)[0] - (*(int**)p2)[0];
}

int findLongestChain(int** pairs, int n, int* pairsColSize)
{
    qsort(pairs, n, sizeof(int*), cmp);
    int dp[1000];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (pairs[i][0] > pairs[j][1])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}
