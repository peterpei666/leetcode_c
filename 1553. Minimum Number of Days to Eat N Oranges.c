#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

int minDays(int n)
{
    if(n<=1)
    {
        return n;
    }
    return 1+min(n%2+minDays(n/2),n%3+minDays(n/3));
}
