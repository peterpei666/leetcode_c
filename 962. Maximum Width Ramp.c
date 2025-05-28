#include <stdio.h>
#include <stdlib.h>

int* list;

int cmp(const void* p1,const void* p2)
{
    int a=*(int*)p1;
    int b=*(int*)p2;
    return list[a]!=list[b]?list[a]-list[b]:a-b;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

inline int min(int a,int b)
{
    return a<b?a:b;
}

int maxWidthRamp(int* nums, int n)
{
    int i;
    int minidx=n,maxlen=0;
    int idx[n];
    for(i=0;i<n;i++)
    {
        idx[i]=i;
    }
    list=nums;
    qsort(idx,n,sizeof(int),cmp);
    for(i=0;i<n;i++)
    {
        maxlen=max(maxlen,idx[i]-minidx);
        minidx=min(minidx,idx[i]);
    }
    return maxlen;
}
