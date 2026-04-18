#include <stdio.h>
#include <stdlib.h>

int mirrorDistance(int n)
{
    int temp = n;
    long long rev = 0;
    while (temp)
    {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return (int)llabs(rev - n);
}
