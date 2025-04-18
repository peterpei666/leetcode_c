#include <stdio.h>
#include <stdlib.h>

int countPairs(int* nums, int numsSize, int k)
{
    int i,j,count=0;
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]==nums[j]&&(i*j)%k==0)
            {
                count++;
            }
        }
    }
    return count;
}

