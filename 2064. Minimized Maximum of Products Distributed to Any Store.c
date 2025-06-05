#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int minimizedMaximum(int n, int* quantities, int m)
{
    int i,l,r,ans=-1;
    l=1;
    r=0;
    for(i=0;i<m;i++)
    {
        r=max(quantities[i],r);
    }
    while(r>=l)
    {
        int mid=(r-l)/2+l;
        if(mid==0)
        {
            break;
        }
        int temp=0;
        for(i=0;i<m;i++)
        {
            temp+=quantities[i]/mid;
            if(quantities[i]%mid)
            {
                temp++;
            }
        }
        if(temp<=n)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}
