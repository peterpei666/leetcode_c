#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

inline short max(short a,short b)
{
    return a>b?a:b;
}

inline short min(short a,short b)
{
    return a<b?a:b;
}

short find(short parent[],int x)
{
    if(parent[x]==x)
    {
        return x;
    }
    parent[x]=find(parent,parent[x]);
    return parent[x];
}

inline void unite(short parent[],int a,int b)
{
    short p1=find(parent,a);
    short p2=find(parent,b);
    parent[max(p1,p2)]=min(p1,p2);
}

bool* friendRequests(int n, int** restrictions, int restrictionsSize, int* restrictionsColSize, int** requests, int m, int* requestsColSize, int* returnSize)
{
    int i,j,k;
    short parent[n];
    short temp[n];
    bool f;
    bool* ret=(bool*)malloc(sizeof(bool)*m);
    for(i=0;i<n;i++)
    {
        parent[i]=i;
    }
    for(i=0;i<m;i++)
    {
        memcpy(temp,parent,sizeof(parent));
        unite(temp,requests[i][0],requests[i][1]);
        f=true;
        for(j=0;j<restrictionsSize;j++)
        {
            if(find(temp,restrictions[j][0])==find(temp,restrictions[j][1]))
            {
                f=false;
                break;
            }
        }
        ret[i]=f;
        if(f)
        {
            memcpy(parent,temp,sizeof(temp));
        }
    }
    *returnSize=m;
    return ret;
}
