#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

int numSubseq(int* nums, int n, int target)
{
    int l=0,r=n-1;
    int i,ans=0;
    const int mod=1e9+7;
    int list[n];
    list[0]=1;
    for(i=1;i<n;i++)
    {
        list[i]=list[i-1]*2%mod;
    }
    qsort(nums,n,sizeof(int),cmp);
    while(l<=r)
    {
        if(nums[l]+nums[r]<=target)
        {
            ans=(ans+list[r-l])%mod;
            l++;
        }
        else
        {
            r--;
        }
    }
    return ans;
}
