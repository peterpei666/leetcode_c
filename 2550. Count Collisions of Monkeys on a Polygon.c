#include <stdio.h>
#include <stdlib.h>

const int mod=1e9+7;

int qpow(int n)
{
    long long temp=2;
    long long cur=1;
    while(n)
    {
        if(n&1)
        {
            cur=cur*temp%mod;
        }
        n>>=1;
        temp=temp*temp%mod;
    }
    return cur%mod;
}

int monkeyMove(int n)
{
    return (qpow(n)-2+mod)%mod;
}
