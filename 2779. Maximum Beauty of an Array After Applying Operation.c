#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

int maximumBeauty(int* nums, int n, int k)
{
    int i,j;
    int ans=0;
    qsort(nums,n,sizeof(int),cmp);
    for(i=0,j=0;i<n;i++)
    {
        while(j<n&&nums[j]<=nums[i]+2*k)
        {
            j++;
        }
        ans=max(ans,j-i);
        if(j==n)
        {
            break;
        }
    }
    return ans;
}
