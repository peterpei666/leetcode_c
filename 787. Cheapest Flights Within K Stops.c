#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INF 100000000

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k)
{
    int i,j,u,v,p,min;
    int* dist_pre=(int*)malloc(n*sizeof(int));
    int* dist_cur=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        dist_pre[i]=INF;
    }
    dist_pre[src]=0;
    for(i=0;i<=k;i++)
    {
        memcpy(dist_cur,dist_pre,n*sizeof(int));
        for(j=0;j<flightsSize;j++)
        {
            u=flights[j][0];
            v=flights[j][1];
            p=flights[j][2];
            if(dist_pre[u]!=INF&&dist_pre[u]+p<dist_cur[v])
            {
                dist_cur[v]=dist_pre[u]+p;
            }
        }
        memcpy(dist_pre,dist_cur,n*sizeof(int));
    }
    min=dist_pre[dst];
    free(dist_pre);
    free(dist_cur);
    if(min==INF)
    {
        return -1;
    }
    else
    {
        return min;
    }
}
