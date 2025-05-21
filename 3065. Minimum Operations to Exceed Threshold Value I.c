#include <stdio.h>
#include <stdlib.h>

int minOperations(int* nums, int n, int k)
{
    int i,count=0;
    for(i=0;i<n;i++)
    {
        if(nums[i]<k)
        {
            count++;
        }
    }
    return count;
}
