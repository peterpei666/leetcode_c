#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int find(int parent[],int x)
{
    if(parent[x]<0)
    {
        return x;
    }
    parent[x]=find(parent,parent[x]);
    return parent[x];
}

bool unite(int parent[],int x,int y)
{
    int p1=find(parent,x);
    int p2=find(parent,y);
    if(p1==p2)
    {
        return false;
    }
    if(parent[p1]<parent[p2])
    {
        parent[p1]+=parent[p2];
        parent[p2]=p1;
    }
    else
    {
        parent[p2]+=parent[p1];
        parent[p1]=p2;
    }
    return true;
}

int* findRedundantDirectedConnection(int** edges, int n, int* edgesColSize, int* returnSize)
{
    int i;
    int e1=-1,e2=-1;
    int parent[n+1];
    int in[n+1];
    memset(parent,-1,sizeof(parent));
    memset(in,-1,sizeof(in));
    for(i=0;i<n;i++)
    {
        if(in[edges[i][1]]!=-1)
        {
            e1=i;
            e2=in[edges[i][1]];
            break;
        }
        in[edges[i][1]]=i;
    }
    *returnSize=2;
    for(i=0;i<n;i++)
    {
        if(i==e1)
        {
            continue;
        }
        if(!unite(parent,edges[i][0],edges[i][1]))
        {
            
            if(e1!=-1)
            {
                return edges[e2];
            }
            else
            {
                return edges[i];
            }
        }
    }
    return edges[e1];
}
