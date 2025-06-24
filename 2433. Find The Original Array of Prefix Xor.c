#include <stdio.h>
#include <stdlib.h>

int* findArray(int* pref, int n, int* returnSize)
{
    int i;
    int* ret=(int*)malloc(sizeof(int)*n);
    ret[0]=pref[0];
    for(i=1;i<n;i++)
    {
        ret[i]=pref[i]^pref[i-1];
    }
    *returnSize=n;
    return ret;
}
