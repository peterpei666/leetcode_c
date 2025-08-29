#include <stdio.h>
#include <stdlib.h>

long long flowerGame(int n, int m)
{
    return ((long long)n / 2) * ((m + 1) / 2) + ((long long)m / 2) * ((n + 1) / 2);
}
