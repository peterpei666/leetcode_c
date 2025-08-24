#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int longestSubarray(int* nums, int n)
{
    int prev=-1,temp=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        while(i<n&&nums[i]==1)
        {
            temp++;
            i++;
        }
        ans=max(ans,prev+temp);
        if(i<n&&nums[i]==0)
        {
            if(temp==0)
            {
                prev=0;
            }
            else
            {
                prev=temp;
                temp=0;
            }
        }
    }
    return ans;
}
