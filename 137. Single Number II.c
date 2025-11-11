#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int n)
{
    int t1 = 0, t2 = 0;
    for (int i = 0; i < n; i++)
    {
        t1 = (t1 ^ nums[i]) & (~t2);
        t2 = (t2 ^ nums[i]) & (~t1);
    }
    return t1;
}
