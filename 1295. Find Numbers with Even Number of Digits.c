#include <stdio.h>
#include <stdlib.h>

int digit(int x)
{
    int count=0;
    while(x)
    {
        count++;
        x/=10;
    }
    return count;
}

int findNumbers(int* nums, int numsSize)
{
    int count=0,i;
    for(i=0;i<numsSize;i++)
    {
        if(digit(nums[i])%2==0)
        {
            count++;
        }
    }
    return count;
}
