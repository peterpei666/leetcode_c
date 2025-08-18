#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long pre[100001];

void merge(int l,int mid,int r)
{
    long long temp[r-l+1];
    memcpy(temp,pre+l,sizeof(long long)*(r-l+1));
    int i=l,j=mid+1;
    int idx=l;
    while(i<=mid&&j<=r)
    {
        if(temp[i-l]<temp[j-l])
        {
            pre[idx]=temp[i-l];
            i++;
        }
        else
        {
            pre[idx]=temp[j-l];
            j++;
        }
        idx++;
    }
    while(i<=mid)
    {
        pre[idx]=temp[i-l];
        i++;
        idx++;
    }
}

void merge_sort(int l,int r,int* ans,int lower,int upper)
{
    if(l>=r)
    {
        return;
    }
    int mid=(l+r)/2;
    merge_sort(l,mid,ans,lower,upper);
    merge_sort(mid+1,r,ans,lower,upper);
    int i=mid+1,j=mid+1;
    for(int k=l;k<=mid;k++)
    {
        while(i<=r&&pre[i]-pre[k]<lower)
        {
            i++;
        }
        while(j<=r&&pre[j]-pre[k]<=upper)
        {
            j++;
        }
        (*ans)+=j-i;
    }
    merge(l,mid,r);
}

int countRangeSum(int* nums, int n, int lower, int upper)
{
    pre[0]=0;
    for(int i=0;i<n;i++)
    {
        pre[i+1]=pre[i]+nums[i];
    }
    int ans=0;
    merge_sort(0,n,&ans,lower,upper);
    return ans;
}
