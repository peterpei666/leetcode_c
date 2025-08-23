#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    int* a=*((int**)p1);
    int* b=*((int**)p2);
    return a[0]==b[0]?b[1]-a[1]:a[0]-b[0];
}

int maxEnvelopes(int** envelopes, int n, int* envelopesColSize)
{
    qsort(envelopes,n,sizeof(int*),cmp);
    int ans[n];
    int sz=0;
    for(int i=0;i<n;i++)
    {
        if(sz==0||envelopes[i][1]>ans[sz-1])
        {
            ans[sz]=envelopes[i][1];
            sz++;
        }
        else
        {
            int l=0,r=sz;
            while(l<r)
            {
                int mid=l+(r-l)/2;
                if(ans[mid]<envelopes[i][1])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid;
                }
            }
            ans[l]=envelopes[i][1];
        }
    }
    return sz;
}
