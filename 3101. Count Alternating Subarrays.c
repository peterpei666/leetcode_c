#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long countAlternatingSubarrays(int* nums, int n)
{
    int i,prev;
    long long cnt=n;
    for(i=1,prev=0;i<n;i++)
    {
        if(nums[i]!=nums[i-1])
        {
            cnt+=(long long)(i-prev);
        }
        else
        {
            prev=i;
        }
    }
    return cnt;
}
