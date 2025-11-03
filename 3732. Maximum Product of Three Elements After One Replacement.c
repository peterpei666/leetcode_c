#include <stdio.h>
#include <stdlib.h>

inline int abs(int a)
{
    return a >= 0 ? a : -a;
}

long long maxProduct(int* nums, int n)
{
    long long a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        long long ax = abs(nums[i]);
        if (ax >= a)
        {
            b = a;
            a = ax;
        }
        else if (ax > b)
        {
            b = ax;
        }
    }
    return 100000LL * a * b;
}
