#include <stdio.h>
#include <stdlib.h>

int rangeBitwiseAnd(int left, int right)
{
    int ret=0,i;
    for(i=0;right;right>>=1,left>>=1,i++)
    {
        if((right&1)&&right-1<left)
        {
            ret+=(1<<i);
        }
    }
    return ret;
}
