#include <stdio.h>
#include <stdlib.h>

long long zeroFilledSubarray(int* nums, int n)
{
    long long ans=0;
    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i])
        {
            temp=0;
        }
        else
        {
            temp++;
            ans+=temp;
        }
    }
    return ans;
}
