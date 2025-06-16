#include <stdio.h>
#include <stdlib.h>

int* grayCode(int n, int* returnSize)
{
    int i;
    int* ret=(int*)malloc(sizeof(int)*(1<<n));
    for(i=0;i<(1<<n);i++)
    {
        ret[i]=i^(i>>1);
    }
    *returnSize=1<<n;
    return ret;
}
