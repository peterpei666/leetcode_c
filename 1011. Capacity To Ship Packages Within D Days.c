#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int shipWithinDays(int* weights, int n, int days)
{
    int i,mid,c,d;
    int l=0;
    int r=500*50000;
    for(i=0;i<n;i++)
    {
        l=maxi(l,weights[i]);
    }
    while(l<r)
    {
        c=0;
        d=1;
        mid=(l+r)/2;
        for(i=0;i<n&&d<=days;i++)
        {
            c+=weights[i];
            if(c>mid)
            {
                c=weights[i];
                d++;
            }
        }
        if(d>days)
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    return l;
}
