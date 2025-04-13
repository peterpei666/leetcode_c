#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long powmod(long long x,long long y)
{
    if(y==0)
    {
        return 1;
    }
    long long ans=powmod(x,y/2);
    if(y%2)
    {
        return (ans*ans*x)%MOD;
    }
    else
    {
        return (ans*ans)%MOD;
    }
}

int countGoodNumbers(long long n)
{
    long long i;
    if(n==1)
    {
        return 5;
    }
    if(n%2)
    {
        i=powmod(4,n/2)*powmod(5,n-n/2)%MOD;
        return (int)i;
    }
    else
    {
        i=powmod(4,n/2)*powmod(5,n/2)%MOD;
        return (int)i;
    }
}
