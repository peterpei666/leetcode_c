#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

bool valid(int* nums,int n,int p,int dif)
{
    int i,cnt=0;
    for(i=0;i<n-1&&cnt<p;i++)
    {
        if(nums[i+1]-nums[i]<=dif)
        {
            cnt++;
            i++;
        }
    }
    return cnt>=p;
}

int minimizeMax(int* nums, int n, int p)
{
    int l,r,mid;
    qsort(nums,n,sizeof(int),cmp);
    l=0;
    r=nums[n-1];
    while(l<r)
    {
        mid=(r-l)/2+l;
        if(valid(nums,n,p,mid))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return l;
}
