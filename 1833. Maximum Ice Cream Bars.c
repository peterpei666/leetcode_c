#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int maxIceCream(int* costs, int n, int coins)
{
    int i,m=0,ans=0;
    for(i=0;i<n;i++)
    {
        m=max(m,costs[i]);
    }
    int cnt[m+1];
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<n;i++)
    {
        cnt[costs[i]]++;
    }
    for(i=1;i<=m;i++)
    {
        if(coins/i>=cnt[i])
        {
            coins-=i*cnt[i];
            ans+=cnt[i];
        }
        else
        {
            ans+=coins/i;
            break;
        }
    }
    return ans;
}
