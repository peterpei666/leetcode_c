#include <stdio.h>
#include <stdlib.h>

int minOperations(int n)
{
    int i,sum=0;
    for(i=n-1;i>0;i-=2)
    {
        sum+=i;
    }
    return sum;
}
