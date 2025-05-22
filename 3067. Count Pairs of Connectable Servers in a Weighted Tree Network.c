#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int p;
    int w;
} pair;

int dfs(int node,int parent,int n,pair list[n][n],int sz[n],int s,int dis)
{
    int i,total=0,next,weight;
    if(dis%s==0)
    {
        total++;
    }
    for(i=0;i<sz[node];i++)
    {
        next=list[node][i].p;
        weight=list[node][i].w;
        if(next!=parent)
        {
            total+=dfs(next,node,n,list,sz,s,dis+weight);
        }
        
    }
    return total;
}

int* countPairsOfConnectableServers(int** edges, int m, int* edgesColSize, int signalSpeed, int* returnSize)
{
    int i,j,k,size,res;
    int n=m+1;
    pair list[n][n];
    int sz[n];
    int cnt[n];
    memset(sz,0,sizeof(sz));
    for(i=0;i<m;i++)
    {
        list[edges[i][0]][sz[edges[i][0]]]=(pair){edges[i][1],edges[i][2]};
        sz[edges[i][0]]++;
        list[edges[i][1]][sz[edges[i][1]]]=(pair){edges[i][0],edges[i][2]};
        sz[edges[i][1]]++;
    }
    int* ret=(int*)malloc(sizeof(int)*n);
    for(k=0;k<n;k++)
    {
        size=0;
        for(i=0;i<sz[k];i++)
        {
            res=dfs(list[k][i].p,k,n,list,sz,signalSpeed,list[k][i].w);
            if(res)
            {
                cnt[size]=res;
                size++;
            }
        }
        ret[k]=0;
        for(i=0;i<size;i++)
        {
            for(j=i+1;j<size;j++)
            {
                ret[k]+=cnt[i]*cnt[j];
            }
        }
    }
    *returnSize=n;
    return ret;
}
