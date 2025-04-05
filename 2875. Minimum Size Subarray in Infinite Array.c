#include <stdio.h>
#include <stdlib.h>

inline int min(int a,int b)
{
    return a>b?b:a;
}

int minSizeSubarray(int* nums, int numsSize, int target)
{
    int sum=0;
    int time;
    int i=0,j=0,rest,temp,minsize=numsSize;
    for(i=0;i<numsSize;i++)
    {
        sum+=nums[i];
        if(sum>target)
        {
            break;
        }
    }
    time=target/sum;
    rest=target%sum;
    if(rest==0)
    {
        return time*numsSize;
    }
    for(i=0;i<2*numsSize;i++)
    {
        rest-=nums[i%numsSize];
        while(j<i&&rest<0)
        {
            rest+=nums[j%numsSize];
            j++;
        }
        if(rest==0)
        {
            temp=i-j+1;
            minsize=min(temp,minsize);
        }
        if(minsize==1)
        {
            break;
        }
    }
    if(minsize==numsSize)
    {
        return -1;
    }
    return minsize+time*numsSize;
}
