#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int minOperations(int* nums, int numsSize, int k)
{
    int i,count=0;
    bool found[100];
    memset(found,false,100);
    for(i=0;i<numsSize;i++)
    {
        if(found[nums[i]-1]==false)
        {
            found[nums[i]-1]=true;
            if(nums[i]<k)
            {
                return -1;
            }
            else if(nums[i]>k)
            {
                count++;
            }
        }
    }
    return count;
}
