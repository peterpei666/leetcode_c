#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target)
{
    int left,right,mid;
    left=0;
    right=numsSize-1;
    while(left<right)
    {
        mid=(left+right)/2;
        if(nums[mid]<target)
        {
            left=mid+1;
        }
        else if(nums[mid]>target)
        {
            right=mid-1;
        }
        else
        {
            return mid;
        }
    }
    if(target>nums[left])
    {
        return left+1;
    }
    return left;
}
