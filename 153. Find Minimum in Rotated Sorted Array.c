#include <stdio.h>
#include <stdlib.h>

int findMin(int* nums, int numsSize)
{
    if(nums[0]<nums[numsSize-1])
    {
        return nums[0];
    }
    int l,m,r;
    l=0;
    r=numsSize-1;
    while(l<r)
    {
        m=l+(r-l)/2;
        if(nums[m]>nums[r])
        {
            l=m+1;
        }
        else
        {
            r=m;
        }
    }
    return nums[l];
}
