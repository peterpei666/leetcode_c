#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double new21Game(int n, int k, int maxPts)
{
    double dp[n+1];
    dp[0]=1.0;
    double temp=k?1.0:0.0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=temp/maxPts;
        if(i<k)
        {
            temp+=dp[i];
        }
        if(i-maxPts>=0&&i-maxPts<k)
        {
            temp-=dp[i-maxPts];
        }
    }
    double ans=0;
    for(int i=k;i<=n;i++)
    {
        ans+=dp[i];
    }
    return ans;
}
