#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 256

typedef struct
{
    unsigned long long list[N/8];
} bitset;

static inline void reset_all(bitset* a)
{
    memset(a->list,0,N);
}

static inline void reset(bitset* a,int i)
{
    a->list[i>>6]&=~(1ULL<<(i&63));
}

static inline void set_all(bitset* a)
{
    memset(a->list,-1,N);
}

static inline void set(bitset* a,int i)
{
    a->list[i>>6]|=1ULL<<(i&63);
}

static inline void flip(bitset* a,int i)
{
    a->list[i>>6]^=1ULL<<(i&63);
}

static inline bool test(const bitset* a,int i)
{
    return (a->list[i>>6]&(1ULL<<(i&63)))!=0;
}

static inline int count(const bitset* a)
{
    int i,cnt=0;
    for(i=0;i<N/8;i++)
    {
        cnt+=__builtin_popcountll(a->list[i]);
    }
    return cnt;
}

int uniqueXorTriplets(int* nums, int n)
{
    int i,j,k=0,temp;
    bitset find,ret;
    int f1[2048];
    f1[0]=0;
    k++;
    reset_all(&find);
    reset_all(&ret);
    set(&find,0);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            temp=nums[i]^nums[j];
            if(test(&find,temp)==false)
            {
                set(&find,temp);
                f1[k]=temp;
                k++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<k;j++)
        {
            set(&ret,nums[i]^f1[j]);
        }
    }
    return count(&ret);
}
