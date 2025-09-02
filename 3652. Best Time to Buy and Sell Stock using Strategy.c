#include <stdio.h>
#include <stdlib.h>

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

long long maxProfit(int* prices, int pricesSize, int* strategy, int strategySize, int k)
{
    int n = pricesSize;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += 1LL * prices[i] * strategy[i];
    }
    long long temp = 0;
    for (int i = k / 2; i < k; i++)
    {
        temp += 1LL * prices[i];
    }
    for (int i = k; i < n; i++)
    {
        temp += 1LL * prices[i] * strategy[i];
    }
    ans = max(ans, temp);
    for (int i = 0; i < n - k; i++)
    {
        temp = temp + prices[i] * strategy[i] - prices[i + k / 2] + prices[i + k] * (1 - strategy[i + k]);
        ans = max(ans, temp);
    }
    return ans;
}
