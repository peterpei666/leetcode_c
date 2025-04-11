#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool symmetric(int x)
{
    if(x<100)
    {
        if(x%11==0)
        {
            return true;
        }
        return false;
    }
    if(x>1000)
    {
        int a,b,c,d;
        a=x/1000;
        b=x/100%10;
        c=x/10%10;
        d=x%10;
        if(a+b==c+d)
        {
            return true;
        }
        return false;
    }
    return false;
}

int countSymmetricIntegers(int low, int high)
{
    int i,count=0;
    for(i=low;i<=high;i++)
    {
        if(symmetric(i))
        {
            count++;
        }
    }
    return count;
}
