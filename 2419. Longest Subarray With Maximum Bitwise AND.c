#include <stdio.h>
#include <stdlib.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int longestSubarray(int* nums, int n)
{
    int i,m=0;
    int len=0,cur=0;
    for(i=0;i<n;i++)
    {
        m=maxi(m,nums[i]);
    }
    for(i=0;i<n;i++)
    {
        if(nums[i]==m)
        {
            cur++;
            len=maxi(len,cur);
        }
        else
        {
            cur=0;
        }
    }
    return len;
}
