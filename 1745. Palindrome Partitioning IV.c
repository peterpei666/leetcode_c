#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 2000

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

bool dfs(int n,int i,int k,bitset pal[],bitset valid[],bitset memo[])
{
    if(test(&valid[k-1],i))
    {
        return test(&memo[k-1],i);
    }
    if(n-i==k)
    {
        return true;
    }
    set(&valid[k-1],i);
    if(k==1)
    {
        if(test(&pal[i],n-1))
        {
            set(&memo[k-1],i);
            return true;
        }
        return false;
    }
    for(int j=i+1;j<n-k+2;j++)
    {
        if(test(&pal[i],j-1)&&dfs(n,j,k-1,pal,valid,memo))
        {
            set(&memo[k-1],i);
            return true;
        }
    }
    return false;
}

bool checkPartitioning(char* s)
{
    int n=(int)strlen(s);
    bitset pal[n];
    for(int i=0;i<n;i++)
    {
        reset_all(&pal[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(s[i]==s[j]&&(j-i<2||test(&pal[i+1],j-1)))
            {
                set(&pal[i],j);
            }
        }
    }
    bitset valid[3];
    bitset memo[3];
    for(int i=0;i<3;i++)
    {
        reset_all(&valid[i]);
        reset_all(&memo[i]);
    }
    return dfs(n,0,3,pal,valid,memo);
}
