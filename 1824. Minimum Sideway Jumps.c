#include <stdio.h>
#include <stdlib.h>

#define INF 2000000000

inline int min(int a,int b)
{
    return a<b?a:b;
}

int minSideJumps(int* obstacles, int obstaclesSize)
{
    int dp[3],i,d;
    dp[0]=1;
    dp[1]=0;
    dp[2]=1;
    for(i=0;i<obstaclesSize;i++)
    {
        if(obstacles[i]>0)
        {
            dp[obstacles[i]-1]=INF;
        }
        for(d=0;d<3;d++)
        {
            if(d!=obstacles[i]-1)
            {
                dp[d]=min(dp[d],min(dp[(d+1)%3],dp[(d+2)%3])+1);
            }
        }
    }
    return min(dp[0],min(dp[1],dp[2]));
}
