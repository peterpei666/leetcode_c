#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int* list;
    int size;
} NumArray;

void build(int node,int start,int end,NumArray* obj,int* nums)
{
    int mid,left,right;
    if(start==end)
    {
        obj->list[node]=nums[start];
    }
    else
    {
        mid=(start+end)/2;
        left=node*2;
        right=node*2+1;
        build(left,start,mid,obj,nums);
        build(right,mid+1,end,obj,nums);
        obj->list[node]=obj->list[left]+obj->list[right];
    }
}

NumArray* numArrayCreate(int* nums, int numsSize)
{
    NumArray* obj=(NumArray*)malloc(sizeof(NumArray));
    obj->list=(int*)calloc(4*numsSize,sizeof(int));
    build(1,0,numsSize-1,obj,nums);
    obj->size=numsSize;
    return obj;
}

int query(int node,int start,int end,int l,int r,NumArray* obj)
{
    if(r<start||l>end)
    {
        return 0;
    }
    if(r>=end&&l<=start)
    {
        return obj->list[node];
    }
    int mid,left,right;
    mid=(start+end)/2;
    left=query(node*2,start,mid,l,r,obj);
    right=query(node*2+1,mid+1,end,l,r,obj);
    return left+right;
}
int numArraySumRange(NumArray* obj, int left, int right)
{
    return query(1,0,obj->size-1,left,right,obj);
}

void numArrayFree(NumArray* obj)
{
    free(obj->list);
    free(obj);
}
