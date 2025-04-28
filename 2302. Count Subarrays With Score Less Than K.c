#include <stdio.h>
#include <stdlib.h>

long long countSubarrays(int* nums, int numsSize, long long k)
{
    long long sum=0,count=0;
    int i,j=0;
    for(i=0;i<numsSize;i++)
    {
        while(j<numsSize&&(sum+nums[j])*(j-i+1)<k)
        {
            sum+=(long long)nums[j];
            j++;
        }
        count+=(long long)(j-i);
        sum-=nums[i];
    }
    return count;
}
