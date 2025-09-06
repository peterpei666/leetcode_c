#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int findMinMoves(int* machines, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += machines[i];
    }
    if (sum % n)
    {
        return -1;
    }
    int bal = 0, ans = 0;
    sum /= n;
    for (int i = 0; i < n; i++)
    {
        int dif = machines[i] - sum;
        bal += dif;
        ans = max(ans, max(abs(bal), dif));
    }
    return ans;
}
