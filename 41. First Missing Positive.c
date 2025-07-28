#include <stdio.h>
#include <stdlib.h>

static inline void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int firstMissingPositive(int* nums, int n)
{
    for(int i=0;i<n;i++)
    {
        while(nums[i]>=1&&nums[i]<=n&&nums[i]!=nums[nums[i]-1])
        {
            swap(&nums[i],&nums[nums[i]-1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(nums[i]!=i+1)
        {
            return i+1;
        }
    }
    return n+1;
}
