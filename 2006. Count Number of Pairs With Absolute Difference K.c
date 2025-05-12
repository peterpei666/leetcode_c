#include <stdio.h>
#include <stdlib.h>

int countKDifference(int* nums, int numsSize, int k)
{
    int cnt=0,i,j;
    for(i=0;i<numsSize-1;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(abs(nums[i]-nums[j])==k)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
