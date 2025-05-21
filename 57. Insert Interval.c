#include <stdio.h>
#include <stdlib.h>

inline int mini(int a,int b)
{
    return a<b?a:b;
}

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int** insert(int** intervals, int n, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes)
{
    int i=0;
    int k=0,capacity=100;
    int** ret=(int**)malloc(sizeof(int*)*capacity);
    while(i<n&&intervals[i][1]<newInterval[0])
    {
        if(k>=capacity)
        {
            capacity+=100;
            ret=(int**)realloc(ret,sizeof(int*)*capacity);
        }
        ret[k]=(int*)malloc(sizeof(int)*2);
        ret[k][0]=intervals[i][0];
        ret[k][1]=intervals[i][1];
        k++;
        i++;
    }
    while(i<n&&intervals[i][0]<=newInterval[1])
    {
        newInterval[0]=mini(newInterval[0],intervals[i][0]);
        newInterval[1]=maxi(newInterval[1],intervals[i][1]);
        i++;
    }
    if(k>=capacity)
    {
        capacity+=100;
        ret=(int**)realloc(ret,sizeof(int*)*capacity);
    }
    ret[k]=(int*)malloc(sizeof(int)*2);
    ret[k][0]=newInterval[0];
    ret[k][1]=newInterval[1];
    k++;
    while(i<n)
    {
        if(k>=capacity)
        {
            capacity+=100;
            ret=(int**)realloc(ret,sizeof(int*)*capacity);
        }
        ret[k]=(int*)malloc(sizeof(int)*2);
        ret[k][0]=intervals[i][0];
        ret[k][1]=intervals[i][1];
        k++;
        i++;
    }
    *returnSize=k;
    *returnColumnSizes=(int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++)
    {
        (*returnColumnSizes)[i]=2;
    }
    return ret;
}
