#include <stdio.h>
#include <stdlib.h>

int clumsy(int n)
{
    int ans[8]={1,2,2,-1,0,0,3,3};
    if(n>4)
    {
        return n+ans[n%4];
    }
    else
    {
        return n+ans[n+3];
    }
}
