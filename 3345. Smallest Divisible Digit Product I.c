#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static inline bool valid(int n,int t)
{
    int pro=1;
    while(n)
    {
        pro*=n%10;
        n/=10;
    }
    return pro%t==0?true:false;
}

int smallestNumber(int n,int t)
{
    while(valid(n,t)==false)
    {
        n++;
    }
    return n;
}
