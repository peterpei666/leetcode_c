#include <stdio.h>
#include <stdlib.h>

int operation(int a,int n)
{
    int i;
    for(i=2;i<=a;i++)
    {
        if(n%i==0)
        {
            return i;
        }
    }
    return -1;
}

int minOperations(int* nums, int n)
{
    int i,ret=0;
    for(i=n-1;i>0;i--)
    {
        if(nums[i]<nums[i-1])
        {
            nums[i-1]=operation(nums[i],nums[i-1]);
            if(nums[i-1]==-1)
            {
                return -1;
            }
            ret++;
        }
    }
    return ret;
}
