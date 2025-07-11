#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p1,const void* p2)
{
    int* a=*((int**)p1);
    int* b=*((int**)p2);
    return a[0]==b[0]?a[1]-b[1]:a[0]-b[0];
}

int mostBooked(int n, int** meetings, int m, int* meetingsColSize)
{
    qsort(meetings,m,sizeof(int*),cmp);
    long long time[n];
    int cnt[n];
    memset(time,0,sizeof(time));
    memset(cnt,0,sizeof(cnt));
    for(int k=0;k<m;k++)
    {
        int l=meetings[k][0];
        int r=meetings[k][1];
        long long mintime=1e10;
        int minp=-1;
        for(int i=0;i<n;i++)
        {
            if(time[i]<=l)
            {
                cnt[i]++;
                time[i]=r;
                minp=-1;
                break;
            }
            else if(time[i]<mintime)
            {
                mintime=time[i];
                minp=i;
            }
        }
        if(minp!=-1)
        {
            cnt[minp]++;
            time[minp]+=r-l;
        }
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(cnt[i]>cnt[ans])
        {
            ans=i;
        }
    }
    return ans;
}
