#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* transformArray(int* nums, int numsSize, int* returnSize)
{
    int i,even=0;
    int* ret=(int*)calloc(sizeof(int),numsSize);
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]%2==0)
        {
            even++;
        }
    }
    for(i=even;i<numsSize;i++)
    {
        ret[i]=1;
    }
    *returnSize=numsSize;
    return ret;
}
