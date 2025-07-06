#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 1251

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

int missingNumber(int* nums, int n)
{
    int i;
    bitset find;
    reset_all(&find);
    for(i=0;i<n;i++)
    {
        set(&find,nums[i]);
    }
    for(i=n;i>0;i--)
    {
        if(test(&find,i)==false)
        {
            return i;
        }
    }
    return 0;
}
