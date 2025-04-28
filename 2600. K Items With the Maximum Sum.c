#include <stdio.h>
#include <stdlib.h>

inline int mini(int a,int b)
{
    return a<b?a:b;
}

int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
{
    int ret=0;
    ret+=mini(k,numOnes);
    k-=ret+numZeros;
    if(k>0)
    {
        ret-=k;
    }
    return ret;
}
