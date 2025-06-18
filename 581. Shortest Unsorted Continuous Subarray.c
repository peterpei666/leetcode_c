#include <stdio.h>
#include <stdlib.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

int findUnsortedSubarray(int* nums, int n)
{
    int i,temp1,temp2;
    int l=-1,r=-2;
    temp1=nums[n-1];
    temp2=nums[0];
    for(i=0;i<n;i++)
    {
        temp1=min(temp1,nums[n-1-i]);
        temp2=max(temp2,nums[i]);
        if(nums[n-1-i]>temp1)
        {
            l=n-1-i;
        }
        if(nums[i]<temp2)
        {
            r=i;
        }
    }
    return r-l+1;
}
