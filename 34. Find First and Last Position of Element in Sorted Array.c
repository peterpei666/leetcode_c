#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int* p=(int*)malloc(2*sizeof(int));
    int left,mid,right;
    *returnSize=2;
    left=0;
    right=numsSize-1;
    while(left<right)
    {
        mid=(left+right)/2;
        if(nums[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            right=mid;
        }
    }
    if(left>=numsSize||nums[left]!=target)
    {
        p[0]=-1;
        p[1]=-1;
    }
    else
    {
        p[0]=left;
        right=numsSize-1;
        while(left<right)
        {
            mid=(left+right+1)/2;
            if(nums[mid]<=target)
            {
                left=mid;
            }
            else
            {
                right=mid-1;
            }
        }
        p[1]=right;
    }
    return p;
}
