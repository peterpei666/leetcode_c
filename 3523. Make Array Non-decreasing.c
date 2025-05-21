#include <stdio.h>
#include <stdlib.h>

int maximumPossibleSize(int* nums, int n)
{
    int i,prev=-1,count=0;
    for(i=0;i<n;i++)
    {
        if(nums[i]>=prev)
        {
            prev=nums[i];
            count++;
        }
    }
    return count;
}
