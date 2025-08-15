#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfFour(int n)
{
    while(n>1)
    {
        if(n&3)
        {
            return false;
        }
        n>>=2;
    }
    return n==1;
}
