#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct
{
    int node;
    int dis;
} pair;

int res;
unsigned char visited[12501];

bool test(int a)
{
    return visited[a>>3]&(1<<(a&7))?true:false;
}

void set(int a)
{
    visited[a>>3]|=1<<(a&7);
}

void reset(int a)
{
    visited[a>>3]&=~(1<<(a&7));
}

inline int min(int a,int b)
{
    return a<b?a:b;
}

void dfs(int node,pair* graph[],int sz[])
{
    int i;
    set(node);
    for(i=0;i<sz[node];i++)
    {
        res=min(res,graph[node][i].dis);
        if(test(graph[node][i].node)==false)
        {
            dfs(graph[node][i].node,graph,sz);
        }
    }
}

int minScore(int n, int** roads, int m, int* roadsColSize)
{
    int i,p1,p2,d;
    pair* graph[n+1];
    int sz[n+1];
    int capacity[n+1];
    res=INT_MAX;
    memset(sz,0,sizeof(sz));
    memset(visited,0,sizeof(visited));
    for(i=1;i<=n;i++)
    {
        capacity[i]=10;
        graph[i]=(pair*)malloc(sizeof(pair)*10);
    }
    for(i=0;i<m;i++)
    {
        p1=roads[i][0];
        p2=roads[i][1];
        d=roads[i][2];
        if(sz[p1]==capacity[p1])
        {
            capacity[p1]*=2;
            graph[p1]=(pair*)realloc(graph[p1],sizeof(pair)*capacity[p1]);
        }
        graph[p1][sz[p1]]=(pair){p2,d};
        sz[p1]++;
        if(sz[p2]==capacity[p2])
        {
            capacity[p2]*=2;
            graph[p2]=(pair*)realloc(graph[p2],sizeof(pair)*capacity[p2]);
        }
        graph[p2][sz[p2]]=(pair){p1,d};
        sz[p2]++;
    }
    dfs(1,graph,sz);
    return res;
}
