#include <stdio.h>
#include <stdlib.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maxFreeTime(int eventTime, int* startTime, int n, int* endTime, int endTimeSize)
{
    int i;
    int ans=0;
    int left=0,cur;
    int gap[n+1];
    int largest[n+1];
    gap[0]=startTime[0];
    for(i=1;i<n;i++)
    {
        gap[i]=startTime[i]-endTime[i-1];
    }
    gap[n]=eventTime-endTime[n-1];
    largest[n]=0;
    for(i=n-1;i>=0;i--)
    {
        largest[i]=maxi(largest[i+1],gap[i+1]);
    }
    for(i=1;i<=n;i++)
    {
        cur=endTime[i-1]-startTime[i-1];
        if(cur<=maxi(left,largest[i]))
        {
            ans=maxi(ans,gap[i-1]+gap[i]+cur);
        }
        ans=maxi(ans,gap[i-1]+gap[i]);
        left=maxi(left,gap[i-1]);
    }
    return ans;
}
