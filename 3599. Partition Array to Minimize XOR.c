#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 32

typedef struct
{
    unsigned char list[N];
} bitset;

static inline void reset_all(bitset* a)
{
    memset(a->list,0,N);
}

static inline void reset(bitset* a,int i)
{
    a->list[i>>3]&=~(1<<(i&7));
}

static inline void set_all(bitset* a)
{
    memset(a->list,-1,N);
}

static inline void set(bitset* a,int i)
{
    a->list[i>>3]|=1<<(i&7);
}

static inline void flip(bitset* a,int i)
{
    a->list[i>>3]^=1<<(i&7);
}

static inline bool test(const bitset* a,int i)
{
    return a->list[i>>3]&(1<<(i&7));
}

static inline bitset or(const bitset* a,const bitset* b)
{
    int i;
    bitset m;
    for(i=0;i<N;i++)
    {
        m.list[i]=a->list[i]|b->list[i];
    }
    return m;
}

static inline bool any(const bitset* a)
{
    int i;
    for(i=0;i<N;i++)
    {
        if(a->list[i])
        {
            return true;
        }
    }
    return false;
}

bitset memo[260];

bool valid(int* nums,int n,int limit,int k)
{
    int i,j,m;
    bitset cur,next;
    for(i=0;i<=n;i++)
    {
        reset_all(&memo[i]);
    }
    for(i=0;i<n;i++)
    {
        int temp=0;
        for(j=i;j<n;j++)
        {
            temp^=nums[j];
            if(temp<=limit)
            {
                set(&memo[i],j+1);
            }
        }
    }
    reset_all(&cur);
    set(&cur,0);
    for(m=0;m<k;m++)
    {
        reset_all(&next);
        for(i=0;i<=n;i++)
        {
            if(test(&cur,i))
            {
                next=or(&next,&memo[i]);
            }
        }
        if(!any(&next))
        {
            return false;
        }
        cur=next;
    }
    return test(&cur,n);
}

int minXor(int* nums, int n, int k)
{
    int i;
    int l=0,r=0,mid;
    for(i=0;i<n;i++)
    {
        r|=nums[i];
    }
    
    while(l<r)
    {
        mid=(r-l)/2+l;
        if(valid(nums,n,mid,k))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return l;
}
