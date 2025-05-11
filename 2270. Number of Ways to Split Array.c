#include <stdio.h>
#include <stdlib.h>

int waysToSplitArray(int* nums, int numsSize)
{
    int cnt=0,i;
    long long sum1=0,sum2=0;
    for(i=0;i<numsSize;i++)
    {
        sum2+=nums[i];
    }
    for(i=0;i<numsSize-1;i++)
    {
        sum1+=nums[i];
        sum2-=nums[i];
        if(sum1>=sum2)
        {
            cnt++;
        }
    }
    return cnt;
}
