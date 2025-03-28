#include <stdio.h>
#include <stdlib.h>

int find(int* parent,int target)
{
    if(parent[target]==target)
    {
        return target;
    }
    else
    {
        parent[target]=find(parent,parent[target]);
        return parent[target];
    }
}

void merge(int* parent,int* rank,int a,int b)
{
    int root1=find(parent,a);
    int root2=find(parent,b);
    if(rank[root1]>rank[root2])
    {
        parent[root2]=root1;
    }
    else if(rank[root1]<rank[root2])
    {
        parent[root1]=root2;
    }
    else
    {
        parent[root2]=root1;
        rank[root1]++;
    }
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
    int i;
    int* parent=(int*)malloc(sizeof(int)*edgesSize);
    int* rank=(int*)malloc(sizeof(int)*edgesSize);
    int* ret=(int*)malloc(sizeof(int)*2);
    *returnSize=2;
    for(i=0;i<edgesSize;i++)
    {
        parent[i]=i;
        rank[i]=1;
    }
    for(i=0;i<edgesSize;i++)
    {
        if(find(parent,edges[i][0]-1)!=find(parent,edges[i][1]-1))
        {
            merge(parent,rank,edges[i][0]-1,edges[i][1]-1);
        }
        else
        {
            ret[0]=edges[i][0];
            ret[1]=edges[i][1];
            break;
        }
    }
    free(parent);
    free(rank);
    return ret;
}
