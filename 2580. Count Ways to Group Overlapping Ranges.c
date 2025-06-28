#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int a;
    int b;
}range;

inline int min(int a,int b)
{
    return a<b?a:b;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

inline bool can_merge(range a,range b)
{
    if(a.a>b.b||b.a>a.b)
    {
        return false;
    }
    return true;
}

int qpow(int a)
{
    const int mod=1e9+7;
    long long ans=1,temp=2;
    while(a)
    {
        if(a&1)
        {
            ans=ans*temp%mod;
        }
        temp=temp*temp%mod;
        a>>=1;
    }
    return ans%mod;
}

inline range merge(range a,range b)
{
    return (range){min(a.a,b.a),max(a.b,b.b)};
}

inline range change(int* r)
{
    return (range){r[0],r[1]};
}

int cmp(const void* p1,const void* p2)
{
    range* r1=(range*)p1;
    range* r2=(range*)p2;
    return r1->a==r2->a?r1->b-r2->b:r1->a-r2->a;
}

int countWays(int** ranges, int n, int* rangesColSize)
{
    int i,cnt=0;
    range list[n];
    range temp;
    for(i=0;i<n;i++)
    {
        list[i]=change(ranges[i]);
    }
    qsort(list,n,sizeof(range),cmp);
    i=0;
    while(i<n)
    {
        temp=list[i];
        i++;
        while(i<n&&can_merge(temp,list[i]))
        {
            temp=merge(temp,list[i]);
            i++;
        }
        cnt++;
    }
    return qpow(cnt);
}
