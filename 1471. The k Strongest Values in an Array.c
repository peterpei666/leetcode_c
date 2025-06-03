#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int center;

int cmp1(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

int cmp2(const void* p1,const void* p2)
{
    if(abs(*(int*)p1-center)==abs(*(int*)p2-center))
    {
        return *(int*)p2-*(int*)p1;
    }
    return abs(*(int*)p2-center)-abs(*(int*)p1-center);
}

int* getStrongest(int* arr, int n, int k, int* returnSize)
{
    int* ret=(int*)malloc(sizeof(int)*k);
    qsort(arr,n,sizeof(int),cmp1);
    center=arr[(n-1)/2];
    qsort(arr,n,sizeof(int),cmp2);
    *returnSize=k;
    memcpy(ret,arr,sizeof(int)*k);
    return ret;
}
