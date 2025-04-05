#include <stdio.h>
#include <stdlib.h>

int subsetXORSum(int* nums, int numsSize)
{
    if(numsSize==0)
    {
        return 0;
    }
    int i,m=0;
    for(i=0;i<numsSize;i++)
    {
        m|=nums[i];
    }
    m<<=numsSize-1;
    return m;
}
