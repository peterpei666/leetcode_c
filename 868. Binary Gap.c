#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static inline int max(int a, int b)
{
    return a > b ? a : b;
}

int binaryGap(int n)
{
    int ans = 0;
    int temp = INT_MIN;
    while (n)
    {
        if (n & 1)
        {
            ans = max(ans, temp);
            temp = 0;
        }
        n >>= 1;
        temp++;
    }
    return ans;
}
