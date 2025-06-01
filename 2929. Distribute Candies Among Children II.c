#include <stdio.h>
#include <stdlib.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

inline int min(int a,int b)
{
    return a<b?a:b;
}

long long distributeCandies(int n, int limit)
{
    int i;
    long long ans=0;
    for(i=0;i<=min(n,limit);i++)
    {
        if(n-i>2*limit)
        {
            continue;
        }
        ans+=min(n-i,limit)-max(0,n-i-limit)+1;
    }
    return ans;
}
