#include <stdio.h>
#include <stdlib.h>

static inline long long min(long long a,long long b)
{
    return a<b?a:b;
}

static inline long long max(long long a,long long b)
{
    return a>b?a:b;
}

int countDigitOne(int n)
{
    int ans=0;
    for(long long i=1;i<=n;i*=10)
    {
        ans+=(n/(i*10))*i+min(max(n%(i*10)-i+1,0LL),i);
    }
    return ans;
}
