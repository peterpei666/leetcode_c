#include <stdio.h>
#include <stdlib.h>

int minOperations(int* nums, int numsSize, int k)
{
    int count=0,m=k,i;
    for(i=0;i<numsSize;i++)
    {
        m^=nums[i];
    }
    while(m)
    {
        count+=m&1;
        m>>=1;
    }
    return count;
}
