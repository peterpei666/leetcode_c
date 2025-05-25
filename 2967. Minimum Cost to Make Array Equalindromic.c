#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

inline long long min(long long a,long long b)
{
    return a<b?a:b;
}

bool palindrome(int n)
{
    int temp=n,sum=0;
    while(n)
    {
        sum*=10;
        sum+=n%10;
        n/=10;
    }
    return sum==temp;
}

inline long long cost(int* nums,int n,int t)
{
    int i;
    long long ans=0;
    for(i=0;i<n;i++)
    {
        ans+=abs(nums[i]-t);
    }
    return ans;
}

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

long long minimumCost(int* nums,int n)
{
    int mid;
    int low,high;
    long long cost1=1e15;
    bool l=true,r=true;
    qsort(nums,n,sizeof(int),cmp);
    if(n&1)
    {
        mid=nums[n/2];
    }
    else
    {
        mid=(nums[n/2]+nums[(n+1)/2])/2;
    }
    if(palindrome(mid))
    {
        cost1=cost(nums,n,mid);
    }
    low=mid-1;
    high=mid+1;
    while(l||r)
    {
        if(l&&palindrome(low))
        {
            l=false;
            cost1=min(cost1,cost(nums,n,low));
        }
        if(r&&palindrome(high))
        {
            r=false;
            cost1=min(cost1,cost(nums,n,high));
        }
        low--;
        high++;
    }
    return cost1;
}
