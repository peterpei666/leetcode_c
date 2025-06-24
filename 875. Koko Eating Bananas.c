#include <stdio.h>
#include <stdlib.h>

int minEatingSpeed(int* piles, int n, int h)
{
    int l=1,r=1e9;
    int i,mid,cur;
    while(l<r)
    {
        mid=(r-l)/2+l;
        cur=0;
        for(i=0;i<n;i++)
        {
            cur+=(piles[i]+mid-1)/mid;
            if(cur>h)
            {
                break;
            }
        }
        if(cur<=h)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return l;
}
