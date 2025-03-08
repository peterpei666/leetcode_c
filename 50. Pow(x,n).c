#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n)
{
    double ans=1;
    int sign=0;
    if(n<0)
    {
        sign=1;
    }
    long long m=(long long)labs(n);
    while(m)
    {
        if(m&1)
        {
            ans*=x;
        }
        x*=x;
        m>>=1;
    }
    if(sign)
    {
        ans=1/ans;
    }
    return ans;
}
