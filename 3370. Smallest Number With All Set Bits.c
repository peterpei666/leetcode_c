#include <stdio.h>
#include <stdlib.h>

int smallestNumber(int n)
{
    return (1 << (sizeof(int) * 8 - __builtin_clz(n))) - 1;
}
