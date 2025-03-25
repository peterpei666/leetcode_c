#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 12
#define MAX_MASK (1<<12)
#define INF 1000000000

int shortestPathLength(int** graph, int graphSize, int* graphColSize)
{
    int n=graphSize;
    int i,j,next,newmask,node,mask,step;
    int final=(1<<n)-1;
    if(n==1)
    {
        return 0;
    }
    int dp[MAX_N][MAX_MASK];
    for(i=0;i<n;i++)
    {
        for(j=0;j<(1<<n);j++)
        {
            dp[i][j]=INF;
        }
    }
    int queue[MAX_N*MAX_MASK][2];
    int head=0,rear=0;
    for(i=0;i<n;i++)
    {
        queue[rear][0]=i;
        queue[rear][1]=1<<i;
        rear++;
        dp[i][1<<i]=0;
    }
    while(head<rear)
    {
        node=queue[head][0];
        mask=queue[head][1];
        step=dp[node][mask];
        head++;
        for(i=0;i<graphColSize[node];i++)
        {
            next=graph[node][i];
            newmask=mask|(1<<next);
            if(dp[next][newmask]>step+1)
            {
                dp[next][newmask]=step+1;
                queue[rear][0]=next;
                queue[rear][1]=newmask;
                rear++;
            }
        }
    }
    int result=INF;
    for(i=0;i<n;i++)
    {
        if(dp[i][final]<result)
        {
            result=dp[i][final];
        }
    }
    return result;
}
