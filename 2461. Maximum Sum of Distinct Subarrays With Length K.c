#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned char visited[12500];

bool test(int a)
{
    return visited[a>>3]&(1<<(a&7))?true:false;
}

void set(int a)
{
    visited[a>>3]|=1<<(a&7);
}

void reset(int a)
{
    visited[a>>3]&=~(1<<(a&7));
}

inline long long maxi(long long a,long long b)
{
    return a>b?a:b;
}

long long maximumSubarraySum(int* nums, int n, int k)
{
    int l,r;
    long long sum=0,ans=0;
    memset(visited,0,sizeof(visited));
    for(l=0,r=0;r<n;r++)
    {
        while(test(nums[r]-1))
        {
            sum-=nums[l];
            reset(nums[l]-1);
            l++;
        }
        sum+=nums[r];
        set(nums[r]-1);
        if(r-l+1==k)
        {
            ans=maxi(ans,sum);
            sum-=nums[l];
            reset(nums[l]-1);
            l++;
        }
    }
    return ans;
}
