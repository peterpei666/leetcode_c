#include <stdio.h>
#include <stdlib.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maxFreeTime(int eventTime, int k, int* startTime, int n, int* endTime, int endTimeSize)
{
    int i;
    int ans=0;
    int gap[n+1];
    int prefix[n+2];
    gap[0]=startTime[0];
    for(i=1;i<n;i++)
    {
        gap[i]=startTime[i]-endTime[i-1];
    }
    gap[n]=eventTime-endTime[n-1];
    prefix[0]=0;
    for(i=1;i<n+2;i++)
    {
        prefix[i]=prefix[i-1]+gap[i-1];
    }
    for(i=k+1;i<n+2;i++)
    {
        ans=maxi(ans,prefix[i]-prefix[i-k-1]);
    }
    return ans;
}
