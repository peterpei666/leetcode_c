#include <stdio.h>
#include <stdlib.h>

int countOdds(int low, int high)
{
    if (!(low & 1))
    {
        low++;
    }
    return (high - low + 2) / 2;
}
