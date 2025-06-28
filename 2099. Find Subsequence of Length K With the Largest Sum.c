#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    int b;
}pair;

int cmp1(const void* p1,const void* p2)
{
    return ((pair*)p2)->a-((pair*)p1)->a;
}

int cmp2(const void* p1,const void* p2)
{
    return ((pair*)p1)->b-((pair*)p2)->b;
}

int* maxSubsequence(int* nums, int n, int k, int* returnSize)
{
    int i;
    pair list[n];
    int* ret=(int*)malloc(sizeof(int)*k);
    for(i=0;i<n;i++)
    {
        list[i]=(pair){nums[i],i};
    }
    qsort(list,n,sizeof(pair),cmp1);
    qsort(list,k,sizeof(pair),cmp2);
    for(i=0;i<k;i++)
    {
        ret[i]=list[i].a;
    }
    *returnSize=k;
    return ret;
}
