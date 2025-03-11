#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target)
{
    if(numsSize==0)
    {
        return-1;
    }
    int left,right,mid,p;
    left=0;
    right=numsSize-1;
    while(left<right)
    {
        mid=left+(-left+right)/2;
        if(nums[right]<nums[mid])
        {
            left=mid+1;
        }
        else
        {
            right=mid;
        }
    }
    p=left;
    if(p==0)
    {
        left=0;
        right=numsSize-1;
    }
    else if(target>=nums[0])
    {
        left=0;
        right=p-1;
    }
    else
    {
        left=p;
        right=numsSize-1;
    }
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
    if(nums[left]!=target)
    {
        return -1;
    }
    else
    {
        return left;
    }
}

int main(void)
{
    int nums[]={1,3};
    printf("%d\n",search(nums,2,3));
    
}
