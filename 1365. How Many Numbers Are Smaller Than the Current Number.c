#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

int getindex(int* unique,int* index,int len,int value)
{
    int l=0;
    int r=len-1;
    int mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(unique[mid]==value)
        {
            return index[mid];
        }
        if(unique[l]==value)
        {
            return index[l];
        }
        if(unique[r]==value)
        {
            return index[r];
        }
        if(unique[mid]>value)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return index[l];
}

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize)
{
    if(numsSize==0)
    {
        *returnSize=0;
        return NULL;
    }
    int i=0,j=0;
    int* sorted=(int*)malloc(sizeof(int)*numsSize);
    int* unique=(int*)malloc(sizeof(int)*numsSize);
    int* index=(int*)malloc(sizeof(int)*numsSize);
    int* result=(int*)malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;
    memcpy(sorted,nums,numsSize*sizeof(int));
    qsort(sorted,numsSize,sizeof(int),compare);
    unique[0]=sorted[0];
    index[0]=0;
    j++;
    for(i=1;i<numsSize;i++)
    {
        if(sorted[i]!=sorted[i-1])
        {
            unique[j]=sorted[i];
            index[j]=i;
            j++;
        }
    }
    for(i=0;i<numsSize;i++)
    {
        result[i]=getindex(unique,index,j,nums[i]);
    }
    free(sorted);
    free(unique);
    free(index);
    return result;
}
