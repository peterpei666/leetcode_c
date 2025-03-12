#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target)
{
    if(numsSize==0)
    {
        return -1;
    }
    int left,right,mid;
    left=0;
    right=numsSize-1;
    while(left<right)
    {
        mid=(left+right)/2;
        if(nums[mid]>target)
        {
            right=mid-1;
        }
        else if(nums[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            return mid;
        }
    }
    if(nums[left]==target)
    {
        return left;
    }
    else
    {
        return -1;
    }
}
