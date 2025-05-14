#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long* sumOfThree(long long num, int* returnSize)
{
    if(num%3)
    {
        *returnSize=0;
        return NULL;
    }
    long long mid=num/3;
    long long* ret=(long long*)malloc(sizeof(long long)*3);
    ret[0]=mid-1;
    ret[1]=mid;
    ret[2]=mid+1;
    *returnSize=3;
    return ret;
}
