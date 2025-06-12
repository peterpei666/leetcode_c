#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b)
{
    int temp;
    while(b)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

int mirrorReflection(int p, int q)
{
    int g=gcd(p,q);
    p=(p/g)%2;
    q=(q/g)%2;
    if(p&&q)
    {
        return 1;
    }
    if(p)
    {
        return 0;
    }
    return 2;
}
