#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 10001

typedef struct
{
    unsigned long long list[N/8+1];
} bitset;

static inline void reset_all(bitset* a)
{
    memset(a->list,0,N);
}

static inline void set(bitset* a,int i)
{
    a->list[i>>6]|=1ULL<<(i&63);
}

static inline bool test(const bitset* a,int i)
{
    return (a->list[i>>6]&(1ULL<<(i&63)))!=0;
}

static inline int max(int a,int b)
{
    return a>b?a:b;
}

static inline int min(int a,int b)
{
    return a<b?a:b;
}

typedef struct
{
    bitset mp;
    int l,r;
} SummaryRanges;


SummaryRanges* summaryRangesCreate(void)
{
    SummaryRanges* obj=(SummaryRanges*)malloc(sizeof(SummaryRanges));
    reset_all(&obj->mp);
    obj->l=10001;
    obj->r=0;
    return obj;
}

void summaryRangesAddNum(SummaryRanges* obj, int value)
{
    set(&obj->mp,value);
    obj->l=min(obj->l,value);
    obj->r=max(obj->r,value);
}

int** summaryRangesGetIntervals(SummaryRanges* obj, int* retSize, int** retColSize)
{
    int** ans=(int**)malloc(sizeof(int*)*16);
    int sz=0,capacity=16;
    int temp[2];
    for(int i=obj->l;i<=obj->r;i++)
    {
        if(test(&obj->mp,i))
        {
            temp[0]=i;
            i++;
            while(i<=obj->r&&test(&obj->mp,i))
            {
                i++;
            }
            temp[1]=i-1;
            if(sz==capacity)
            {
                capacity*=2;
                ans=(int**)realloc(ans,sizeof(int*)*capacity);
            }
            ans[sz]=(int*)malloc(sizeof(int)*2);
            memcpy(ans[sz],temp,sizeof(temp));
            sz++;
        }
    }
    *retSize=sz;
    *retColSize=(int*)malloc(sizeof(int)*sz);
    for(int i=0;i<sz;i++)
    {
        (*retColSize)[i]=2;
    }
    return ans;
}

void summaryRangesFree(SummaryRanges* obj)
{
    free(obj);
}
