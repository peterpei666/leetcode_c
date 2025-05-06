#include <stdio.h>
#include <stdlib.h>

int* buildArray(int* nums, int numsSize, int* returnSize)
{
    const int MOD=10000;
    int i;
    for(i=0;i<numsSize;i++)
    {
        nums[i]+=nums[nums[i]%MOD]%MOD*MOD;
    }
    for(i=0;i<numsSize;i++)
    {
        nums[i]/=MOD;
    }
    *returnSize=numsSize;
    return nums;
}
