#include <stdio.h>
#include <stdlib.h>

int minimumPrefixLength(int* nums, int n)
{
    n--;
    while (n > 0 && nums[n] > nums[n - 1])
    {
        n--;
    }
    return n;
}
