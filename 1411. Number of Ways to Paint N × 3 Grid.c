#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

inline int getmask(int x)
{
    int mask=0;
    for(int i=0;i<3;i++)
    {
        mask|=1<<(3*i+x%3);
        x/=3;
    }
    return mask;
}

inline bool valid_pair(int m1,int m2)
{
    return !(m1&m2);
}

inline bool valid(int mask)
{
    return !((mask&(mask>>3))||(mask&(mask<<3)));
}

int numOfWays(int n)
{
    const int mod=1e9+7;
    int i,j;
    int ans=0;
    int adj[27]={0};
    int masks[27]={0};
    int list[2][27]={0};
    for(i=0;i<27;i++)
    {
        int mask=getmask(i);
        if(valid(mask))
        {
            masks[i]=mask;
        }
    }
    for(i=0;i<27;i++)
    {
        if(masks[i])
        {
            for(j=0;j<27;j++)
            {
                if(masks[j]&&valid_pair(masks[i],masks[j]))
                {
                    adj[i]|=1<<j;
                }
            }
        }
    }
    for(i=0;i<27;i++)
    {
        if(masks[i])
        {
            list[0][i]=1;
        }
    }
    for(j=1;j<n;j++)
    {
        for(i=0;i<27;i++)
        {
            list[j%2][i]=0;
            for(int k=0;k<27;k++)
            {
                if(adj[i]&(1<<k))
                {
                    list[j%2][i]+=list[(j-1)%2][k];
                    list[j%2][i]%=mod;
                }
            }
        }
    }
    for(i=0;i<27;i++)
    {
        ans+=list[(n-1)%2][i];
        ans%=mod;
    }
    return ans;
}
