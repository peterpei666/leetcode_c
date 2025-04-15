#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

long long maxSpending(int** values, int valuesSize, int* valuesColSize)
{
    int i,j;
    int* count=(int*)malloc(sizeof(int)*valuesSize*valuesColSize[0]);
    long long cost=0;
    for(i=0;i<valuesSize;i++)
    {
        memcpy(count+i*valuesColSize[0],values[i],sizeof(int)*valuesColSize[0]);
    }
    qsort(count,valuesSize*valuesColSize[0],sizeof(int),compare);
    for(i=0;i<valuesSize*valuesColSize[0];i++)
    {
        cost+=((long long)(i+1))*((long long)count[i]);
    }
    free(count);
    return cost;
}
