#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int minPairSum(int* nums, int n)
{
    int ans=0;
    int l=0,r=n-1;
    qsort(nums,n,sizeof(int),cmp);
    while(l<r)
    {
        ans=max(ans,nums[l]+nums[r]);
        l++;
        r--;
    }
    return ans;
}
