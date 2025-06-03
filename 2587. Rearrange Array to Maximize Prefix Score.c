#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p2-*(int*)p1;
}

int maxScore(int* nums, int n)
{
    int i,ans=0;
    long long sum=0;
    qsort(nums,n,sizeof(int),cmp);
    for(i=0;i<n&&sum>=0;i++)
    {
        sum+=nums[i];
        if(sum>0)
        {
            ans++;
        }
    }
    return ans;
}
