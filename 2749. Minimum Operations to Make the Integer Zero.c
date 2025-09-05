#include <stdio.h>
#include <stdlib.h>

int makeTheIntegerZero(int num1, int num2)
{
    for (int i = 1; i < 60; i++)
    {
        long long x = num1 - (long long)num2 * i;
        if (x < i)
        {
            break;
        }
        if (__builtin_popcountll(x) <= i)
        {
            return i;
        }
    }
    return -1;
}
