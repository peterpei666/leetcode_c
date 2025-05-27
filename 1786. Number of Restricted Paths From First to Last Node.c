#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct
{
    int node;
    int dis;
} pair;

struct heap
{
    pair* list;
    int size;
    int capacity;
};

struct heap* initialize(int n)
{
    struct heap* h=(struct heap*)malloc(sizeof(struct heap));
    h->size=0;
    h->capacity=n;
    h->list=(pair*)malloc(sizeof(pair)*n);
    return h;
}

inline void swap(pair* a,pair* b)
{
    pair t=*a;
    *a=*b;
    *b=t;
}

void heapify(struct heap* minheap,int i)
{
    int smallest=i;
    int l,r;
    while(1)
    {
        l=2*i+1;
        r=2*i+2;
        if(l<minheap->size&&minheap->list[l].dis<minheap->list[smallest].dis)
        {
            smallest=l;
        }
        if(r<minheap->size&&minheap->list[r].dis<minheap->list[smallest].dis)
        {
            smallest=r;
        }
        if(i==smallest)
        {
            break;
        }
        swap(&minheap->list[i],&minheap->list[smallest]);
        i=smallest;
    }
}

void push(struct heap* minheap,pair n)
{
    if(minheap->size>=minheap->capacity)
    {
        minheap->capacity*=2;
        minheap->list=(pair*)realloc(minheap->list,sizeof(pair)*minheap->capacity);
    }
    int i=minheap->size;
    minheap->size++;
    minheap->list[i]=n;
    while(i&&minheap->list[i].dis<minheap->list[(i-1)/2].dis)
    {
        swap(&minheap->list[i],&minheap->list[(i-1)/2]);
        i=(i-1)/2;
    }
}

void pop(struct heap* minheap)
{
    minheap->size--;
    minheap->list[0]=minheap->list[minheap->size];
    heapify(minheap,0);
}

pair top(struct heap* minheap)
{
    return minheap->list[0];
}

void clear(struct heap* h)
{
    free(h->list);
    free(h);
}

const int mod=1e9+7;

int dfs(int node,pair* graph[],int sz[],int dis[],int dp[],int n)
{
    if(node==n)
    {
        return 1;
    }
    if(dp[node]!=-1)
    {
        return dp[node];
    }
    int i,ans=0;
    pair temp;
    for(i=0;i<sz[node];i++)
    {
        temp=graph[node][i];
        if(dis[temp.node]<dis[node])
        {
            ans+=dfs(temp.node,graph,sz,dis,dp,n);
            ans%=mod;
        }
    }
    dp[node]=ans;
    return ans;
}

int countRestrictedPaths(int n, int** edges, int e, int* edgesColSize)
{
    int i,p1,p2,d,ans;
    pair* graph[n+1];
    pair temp;
    int sz[n+1];
    int dis[n+1];
    int capacity[n+1];
    int dp[n+1];
    struct heap* minheap=initialize(20);
    memset(sz,0,sizeof(sz));
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=n;i++)
    {
        dis[i]=INT_MAX;
        capacity[i]=10;
        graph[i]=(pair*)malloc(sizeof(pair)*10);
    }
    for(i=0;i<e;i++)
    {
        p1=edges[i][0];
        p2=edges[i][1];
        d=edges[i][2];
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
    dis[n]=0;
    push(minheap,(pair){n,0});
    while(minheap->size)
    {
        temp=top(minheap);
        pop(minheap);
        if(temp.dis>dis[temp.node])
        {
            continue;
        }
        for(i=0;i<sz[temp.node];i++)
        {
            if(temp.dis+graph[temp.node][i].dis<dis[graph[temp.node][i].node])
            {
                dis[graph[temp.node][i].node]=temp.dis+graph[temp.node][i].dis;
                push(minheap,(pair){graph[temp.node][i].node,dis[graph[temp.node][i].node]});
            }
        }
    }
    clear(minheap);
    ans=dfs(1,graph,sz,dis,dp,n);
    for(i=1;i<=n;i++)
    {
        free(graph[i]);
    }
    return ans;
}
