#include <stdio.h>
#include <stdlib.h>

int countPartitions(int* nums, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += nums[i];
    }
    if (total & 1)
    {
        return 0;
    }
    return n - 1;
}
