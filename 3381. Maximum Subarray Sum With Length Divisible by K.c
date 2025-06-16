#include <stdio.h>
#include <stdlib.h>

inline long long max(long long a,long long b)
{
    return a>b?a:b;
}

inline long long min(long long a,long long b)
{
    return a<b?a:b;
}

long long maxSubarraySum(int* nums, int n, int k)
{
    int i;
    long long sum=0;
    long long ans;
    long long prefix[k];
    for(i=0;i<k&&i<n;i++)
    {
        sum+=nums[i];
        prefix[i]=sum;
    }
    prefix[k-1]=min(0LL,prefix[k-1]);
    ans=sum;
    for(i=k;i<n;i++)
    {
        sum+=nums[i];
        ans=max(ans,sum-prefix[i%k]);
        prefix[i%k]=min(prefix[i%k],sum);
    }
    return ans;
}
