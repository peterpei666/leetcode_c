#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned char visited[1250];

inline bool test(int a)
{
    return visited[a>>3]&(1<<(a&7))?true:false;
}

inline void set(int a)
{
    visited[a>>3]|=1<<(a&7);
}

inline void reset(int a)
{
    visited[a>>3]&=~(1<<(a&7));
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

int maximumUniqueSubarray(int* nums, int n)
{
    int ans=0,sum=0,i,j;
    memset(visited,0,sizeof(visited));
    for(i=0,j=0;i<n;i++)
    {
        while(test(nums[i]-1))
        {
            sum-=nums[j];
            reset(nums[j]-1);
            j++;
        }
        sum+=nums[i];
        set(nums[i]-1);
        ans=max(ans,sum);
    }
    return ans;
}
