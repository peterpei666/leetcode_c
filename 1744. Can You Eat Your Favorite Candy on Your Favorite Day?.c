#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool* canEat(int* candiesCount, int n, int** queries, int q, int* queriesColSize, int* returnSize)
{
    int i;
    long long prefix[n+1];
    bool* ret=(bool*)malloc(sizeof(bool)*q);
    prefix[0]=0;
    for(i=0;i<n;i++)
    {
        prefix[i+1]=prefix[i]+candiesCount[i];
    }
    for(i=0;i<q;i++)
    {
        if(queries[i][1]+1<=prefix[queries[i][0]+1]&&(long long)(queries[i][1]+1)*queries[i][2]>prefix[queries[i][0]])
        {
            ret[i]=true;
        }
        else
        {
            ret[i]=false;
        }
    }
    *returnSize=q;
    return ret;
}
