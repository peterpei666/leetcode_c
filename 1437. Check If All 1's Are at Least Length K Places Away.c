#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool kLengthApart(int* nums, int numsSize, int k)
{
    int i,len=10000000;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==0)
        {
            len++;
        }
        else
        {
            if(len<k)
            {
                return false;
            }
            len=0;
        }
    }
    return true;
}
