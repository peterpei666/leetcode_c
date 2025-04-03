#include <stdio.h>
#include <stdlib.h>

long long maximumTripletValue(int* nums, int numsSize)
{
    int i;
    long long temp,max=0;
    int* leftmax=(int*)malloc(sizeof(int)*numsSize);
    int* rightmax=(int*)malloc(sizeof(int)*numsSize);
    leftmax[0]=nums[0];
    rightmax[numsSize-1]=nums[numsSize-1];
    for(i=1;i<numsSize;i++)
    {
        if(nums[i]>leftmax[i-1])
        {
            leftmax[i]=nums[i];
        }
        else
        {
            leftmax[i]=leftmax[i-1];
        }
    }
    for(i=numsSize-2;i>=0;i--)
    {
        if(nums[i]>rightmax[i+1])
        {
            rightmax[i]=nums[i];
        }
        else
        {
            rightmax[i]=rightmax[i+1];
        }
    }
    for(i=1;i<numsSize-1;i++)
    {
        temp=((long long)(leftmax[i-1]-nums[i]))*(long long)rightmax[i+1];
        if(max<temp)
        {
            max=temp;
        }
    }
    free(leftmax);
    free(rightmax);
    if(max<0)
    {
        return 0;
    }
    return max;
}

