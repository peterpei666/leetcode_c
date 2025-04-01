#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

inline int min(int a,int b)
{
    if(a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int jump(int* nums, int numsSize)
{
    int i,j,temp;
    int* list=(int*)malloc(sizeof(int)*numsSize);
    list[0]=0;
    for(i=1;i<numsSize;i++)
    {
        list[i]=INF;
    }
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize&&j<=i+nums[i];j++)
        {
            list[j]=min(list[j],list[i]+1);
        }
    }
    temp=list[numsSize-1];
    free(list);
    return temp;
}
