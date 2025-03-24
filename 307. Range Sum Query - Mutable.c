#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int* list;
    int size;
} NumArray;

void build(int node,int start,int end,int*nums,NumArray* obj)
{
    int left,mid,right;
    if(start==end)
    {
        obj->list[node]=nums[start];
    }
    else
    {
        mid=(start+end)/2;
        left=2*node;
        right=2*node+1;
        build(left,start,mid,nums,obj);
        build(right,mid+1,end,nums,obj);
        obj->list[node]=obj->list[left]+obj->list[right];
    }
}

NumArray* numArrayCreate(int* nums, int numsSize)
{
    NumArray* obj=(NumArray*)malloc(sizeof(NumArray));
    obj->list=(int*)calloc(4*numsSize,sizeof(int));
    obj->size=numsSize;
    build(1,0,numsSize-1,nums,obj);
    return obj;
}

void update(NumArray* obj,int node,int index,int val,int start,int end)
{
    if(start==end)
    {
        obj->list[node]=val;
    }
    else
    {
        int mid=(start+end)/2;
        int left=node*2;
        int right=node*2+1;
        if(index<=mid)
        {
            update(obj,left,index,val,start,mid);
        }
        else
        {
            update(obj,right,index,val,mid+1,end);
        }
        obj->list[node]=obj->list[left]+obj->list[right];
    }
}

void numArrayUpdate(NumArray* obj, int index, int val)
{
    update(obj,1,index,val,0,obj->size-1);
}

int query(NumArray* obj,int node,int l,int r,int start,int end)
{
    if(l>end||r<start)
    {
        return 0;
    }
    if(start>=l&&r>=end)
    {
        return obj->list[node];
    }
    int mid=(start+end)/2;
    int left=query(obj,node*2,l,r,start,mid);
    int right=query(obj,node*2+1,l,r,mid+1,end);
    return left+right;
}

int numArraySumRange(NumArray* obj, int left, int right)
{
    return query(obj,1,left,right,0,obj->size-1);
}

void numArrayFree(NumArray* obj)
{
    free(obj->list);
    free(obj);
}
