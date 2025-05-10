#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline long long maxi(long long a,long long b)
{
    return a>b?a:b;
}

long long maxArrayValue(int* nums, int numsSize)
{
    int i;
    long long temp=0,ret=0;
    for(i=numsSize-1;i>=0;i--)
    {
        if(temp>=nums[i])
        {
            temp+=nums[i];
        }
        else
        {
            ret=maxi(ret,temp);
            temp=nums[i];
        }
    }
    ret=maxi(ret,temp);
    return ret;
}
