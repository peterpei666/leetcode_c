#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int maximumEnergy(int* energy, int n, int k)
{
    int ans = INT_MIN;
    for (int i = n - k; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j >= 0; j -= k)
        {
            sum += energy[j];
            ans = max(ans, sum);
        }
    }
    return ans;
}
