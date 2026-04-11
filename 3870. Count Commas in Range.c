#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int countCommas(int n)
{
    return max(0, n - 999);
}
