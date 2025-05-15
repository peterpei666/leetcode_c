#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p2-*(int*)p1;
}

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maxStarSum(int* vals, int n, int** edges, int edgesSize, int* edgesColSize, int k)
{
    int i,j,m=INT_MIN,sum;
    int sz[n];
    int capacity[n];
    int* list[n];
    for(i=0;i<n;i++)
    {
        capacity[i]=10;
        sz[i]=0;
        list[i]=(int*)malloc(sizeof(int)*10);
    }
    for(i=0;i<edgesSize;i++)
    {
        if(sz[edges[i][0]]>=capacity[edges[i][0]])
        {
            capacity[edges[i][0]]*=2;
            list[edges[i][0]]=(int*)realloc(list[edges[i][0]],sizeof(int)*capacity[edges[i][0]]);
        }
        list[edges[i][0]][sz[edges[i][0]]]=vals[edges[i][1]];
        sz[edges[i][0]]++;
        if(sz[edges[i][1]]>=capacity[edges[i][1]])
        {
            capacity[edges[i][1]]*=2;
            list[edges[i][1]]=(int*)realloc(list[edges[i][1]],sizeof(int)*capacity[edges[i][1]]);
        }
        list[edges[i][1]][sz[edges[i][1]]]=vals[edges[i][0]];
        sz[edges[i][1]]++;
    }
    for(i=0;i<n;i++)
    {
        qsort(list[i],sz[i],sizeof(int),cmp);
        sum=vals[i];
        for(j=0;j<k&&j<sz[i];j++)
        {
            if(list[i][j]<=0)
            {
                break;
            }
            sum+=list[i][j];
        }
        free(list[i]);
        m=maxi(m,sum);
    }
    return m;
}
