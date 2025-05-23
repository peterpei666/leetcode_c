#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int find(int x,int parent[])
{
    if(x==parent[x])
    {
        return x;
    }
    else
    {
        parent[x]=find(parent[x],parent);
        return parent[x];
    }
}

void unite(int a,int b,int parent[])
{
    int p1=find(a,parent);
    int p2=find(b,parent);
    if(p1>p2)
    {
        parent[p1]=p2;
    }
    else if(p1<p2)
    {
        parent[p2]=p1;
    }
}

unsigned char visited[25];

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

int findCircleNum(int** isConnected, int n, int* isConnectedColSize)
{
    int i,j,cnt=0;
    int parent[n];
    for(i=0;i<n;i++)
    {
        parent[i]=i;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(isConnected[i][j])
            {
                unite(i,j,parent);
            }
        }
    }
    memset(visited,0,sizeof(visited));
    for(i=0;i<n;i++)
    {
        j=find(i,parent);
        if(test(j)==false)
        {
            set(j);
            cnt++;
        }
    }
    return cnt;
}
