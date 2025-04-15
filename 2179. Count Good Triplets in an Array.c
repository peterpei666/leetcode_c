#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int* tree;
    int size;
} fenwickTree;

inline int lowbit(int index)
{
    return index&(-index);
}

fenwickTree* create(int size)
{
    fenwickTree* list=(fenwickTree*)malloc(sizeof(fenwickTree));
    list->tree=(int*)calloc(sizeof(int),size+1);
    list->size=size;
    return list;
}

void update(fenwickTree* list,int index,int d)
{
    index++;
    while(index<=list->size)
    {
        list->tree[index]+=d;
        index+=lowbit(index);
    }
}

int query(fenwickTree* list,int index)
{
    index++;
    int res=0;
    while(index)
    {
        res+=list->tree[index];
        index-=lowbit(index);
    }
    return res;
}

long long goodTriplets(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int n=nums1Size,i;
    int pos,l,r;
    long long ret=0;
    int* pos2=(int*)malloc(sizeof(int)*n);
    int* reverse=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        pos2[nums2[i]]=i;
    }
    for(i=0;i<n;i++)
    {
        reverse[pos2[nums1[i]]]=i;
    }
    fenwickTree* list=create(n);
    for(i=0;i<n;i++)
    {
        pos=reverse[i];
        l=query(list,pos);
        update(list,pos,1);
        r=(n-1-pos)-(i-l);
        ret+=(long long)l*r;
    }
    free(pos2);
    free(reverse);
    free(list->tree);
    free(list);
    return ret;
}
