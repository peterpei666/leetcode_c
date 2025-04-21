#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkArray(int* nums, int numsSize, int k)
{
    int sum=0,i;
    for(i=0;i<k&&i<numsSize-k+1;i++)
    {
        nums[i]+=sum;
        if(nums[i]<0)
        {
            return false;
        }
        sum-=nums[i];
    }
    for(;i<numsSize-k+1;i++)
    {
        if(i-k>=0)
        {
            sum+=nums[i-k];
        }
        nums[i]+=sum;
        if(nums[i]<0)
        {
            return false;
        }
        sum-=nums[i];
    }
    for(;i<numsSize;i++)
    {
        if(i-k>=0)
        {
            sum+=nums[i-k];
        }
        if(nums[i]+sum!=0)
        {
            return false;
        }
    }
    return true;
}
