#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

inline int min(int a,int b)
{
    return a<b?a:b;
}

inline long long maxll(long long a,long long b)
{
    return a>b?a:b;
}

long long maximumProduct(int* nums, int n, int m)
{
    int i;
    int surmin[n];
    int surmax[n];
    long long ans=(long long)INT_MIN*10;
    surmin[n-1]=nums[n-1];
    surmax[n-1]=nums[n-1];
    for(int i=n-2;i>=0;i--)
    {
        surmin[i]=min(surmin[i+1],nums[i]);
        surmax[i]=max(surmax[i+1],nums[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(i+m-1>=n)
        {
            break;
        }
        ans=maxll(ans,(long long)nums[i]*surmax[i+m-1]);
        ans=maxll(ans,(long long)nums[i]*surmin[i+m-1]);
    }
    return ans;
}
