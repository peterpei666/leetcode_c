#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt;
int capacity;

void dfs(int*** ret,int** retCol,int node,int n,int path[],int p,int** graph,int* graphColSize)
{
    int i;
    path[p]=node;
    if(node==n-1)
    {
        if(cnt>=capacity)
        {
            capacity*=2;
            *ret=(int**)realloc(*ret,sizeof(int*)*capacity);
            *retCol=(int*)realloc(*retCol,sizeof(int)*capacity);
        }
        (*ret)[cnt]=(int*)malloc(sizeof(int)*15);
        memcpy((*ret)[cnt],path,sizeof(int)*(p+1));
        (*retCol)[cnt]=p+1;
        cnt++;
        return;
    }
    for(i=0;i<graphColSize[node];i++)
    {
        dfs(ret,retCol,graph[node][i],n,path,p+1,graph,graphColSize);
    }
}

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes)
{
    int path[20];
    int** ret=(int**)malloc(sizeof(int*)*20);
    *returnColumnSizes=(int*)malloc(sizeof(int)*20);
    capacity=20;
    cnt=0;
    dfs(&ret,returnColumnSizes,0,graphSize,path,0,graph,graphColSize);
    *returnSize=cnt;
    return ret;
}
