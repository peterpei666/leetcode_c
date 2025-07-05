#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int uniqueXorTriplets(int* nums, int n)
{
    int cnt=log2(n);
    if(n<3)
    {
        return n;
    }
    return 1<<(cnt+1);
}
