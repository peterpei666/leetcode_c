#include <stdio.h>
#include <stdlib.h>

int averageValue(int* nums, int n)
{
    int i;
    int sum=0,count=0;
    for(i=0;i<n;i++)
    {
        if(nums[i]%6==0)
        {
            sum+=nums[i];
            count++;
        }
    }
    return count?sum/count:0;
}
