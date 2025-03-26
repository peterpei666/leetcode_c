#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000

int bit[MAX];
int sorted[MAX];

int lowbit(int x)
{
    return x&(-x);
}

void update(int index,int value,int n)
{
    while(index<=n)
    {
        bit[index]+=value;
        index+=lowbit(index);
    }
}

int query(int index)
{
    int sum=0;
    while(index>0)
    {
        sum+=bit[index];
        index-=lowbit(index);
    }
    return sum;
}

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

int discretize(int* nums,int* sorted,int n)
{
    int len=1,i;
    memcpy(sorted,nums,sizeof(int)*n);
    qsort(sorted,n,sizeof(int),compare);
    for(i=1;i<n;i++)
    {
        if(sorted[i]!=sorted[i-1])
        {
            sorted[len]=sorted[i];
            len++;
        }
    }
    return len;
}

int getindex(int* sorted,int len,int value)
{
    int l=0;
    int r=len-1;
    int m;
    while(l<=r)
    {
        m=(l+r)/2;
        if(sorted[m]==value)
        {
            return m+1;
        }
        else if(sorted[m]<value)
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    return -1;
}

int* countSmaller(int* nums, int numsSize, int* returnSize)
{
    if(numsSize==0)
    {
        *returnSize=0;
        return NULL;
    }
    int* list=(int*)malloc(numsSize*sizeof(int));
    *returnSize=numsSize;
    int unique=discretize(nums,sorted,numsSize);
    int i,index;
    for(i=0;i<=unique;i++)
    {
        bit[i]=0;
    }
    for(i=numsSize-1;i>=0;i--)
    {
        index=getindex(sorted,unique,nums[i]);
        list[i]=query(index-1);
        update(index,1,unique);
    }
    return list;
}
