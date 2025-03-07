#include <stdio.h>
#include <stdlib.h>

int divide(int dividend, int divisor)
{
    if(dividend==0)
    {
        return 0;
    }
    int sign=(dividend<0)^(divisor<0),i;
    long long a=labs(dividend),b=labs(divisor),ret=0;
    for(i=31;i>=0;i--)
    {
        if((a>>i)>=b)
        {
            a-=b<<i;
            ret+=1LL<<i;
        }
    }
    if(sign)
    {
        ret*=-1;
    }
    if(ret>2147483647)
    {
        return 2147483647;
    }
    else
    {
        return (int)ret;
    }
}
