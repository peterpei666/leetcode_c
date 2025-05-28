#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dfs(int* graph[],int sz[],int node,int parent,int k)
{
    if(k<0)
    {
        return 0;
    }
    int ans=1,i;
    for(i=0;i<sz[node];i++)
    {
        if(graph[node][i]!=parent)
        {
            ans+=dfs(graph,sz,graph[node][i],node,k-1);
        }
    }
    return ans;
}

int* build(int** edges,int e,int k)
{
    int i,n=e+1,p1,p2;
    int* graph[n];
    int sz[n];
    int capacity[n];
    memset(sz,0,sizeof(sz));
    for(i=0;i<n;i++)
    {
        capacity[i]=10;
        graph[i]=(int*)malloc(sizeof(int)*10);
    }
    for(i=0;i<e;i++)
    {
        p1=edges[i][0];
        p2=edges[i][1];
        if(sz[p1]==capacity[p1])
        {
            capacity[p1]+=10;
            graph[p1]=(int*)realloc(graph[p1],sizeof(int)*capacity[p1]);
        }
        graph[p1][sz[p1]]=p2;
        sz[p1]++;
        if(sz[p2]==capacity[p2])
        {
            capacity[p2]+=10;
            graph[p2]=(int*)realloc(graph[p1],sizeof(int)*capacity[p2]);
        }
        graph[p2][sz[p2]]=p1;
        sz[p2]++;
    }
    int* ret=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        ret[i]=dfs(graph,sz,i,-1,k);
    }
    for(i=0;i<n;i++)
    {
        free(graph[i]);
    }
    return ret;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

int* maxTargetNodes(int** edges1, int n1, int* edges1ColSize, int** edges2, int n2, int* edges2ColSize, int k, int* returnSize)
{
    int i,m=0;
    int* tree1=build(edges1,n1,k);
    int* tree2=build(edges2,n2,k-1);
    for(i=0;i<=n2;i++)
    {
        m=max(m,tree2[i]);
    }
    free(tree2);
    for(i=0;i<=n1;i++)
    {
        tree1[i]+=m;
    }
    *returnSize=n1+1;
    return tree1;
}
