#include <stdio.h>
#include <stdlib.h>

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int maxProfit(int* prices, int n)
{
    int suf[n];
    suf[n-1]=prices[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suf[i]=max(suf[i+1],prices[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,suf[i]-prices[i]);
    }
    return ans;
}
