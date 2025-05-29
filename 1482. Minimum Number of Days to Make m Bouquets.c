#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check(int* bloomDay,int n,int d,int m,int k)
{
    int i,cnt=0;
    for(i=0;i<n;i++)
    {
        if(bloomDay[i]<=d)
        {
            cnt++;
        }
        else
        {
            cnt=0;
        }
        if(cnt==k)
        {
            cnt=0;
            m--;
            if(m==0)
            {
                return true;
            }
        }
    }
    return false;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

int minDays(int* bloomDay, int n, int m, int k)
{
    int i,mid,day=-1;
    int l=0,r=0;
    for(i=0;i<n;i++)
    {
        r=max(r,bloomDay[i]);
    }
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(bloomDay,n,mid,m,k))
        {
            r=mid-1;
            day=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return day;
}
