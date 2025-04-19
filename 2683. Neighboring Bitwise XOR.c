#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool doesValidArrayExist(int* derived, int derivedSize)
{
    int i;
    int* temp=(int*)malloc(sizeof(int)*derivedSize);
    temp[0]=0;
    for(i=1;i<derivedSize;i++)
    {
        temp[i]=temp[i-1]^derived[i-1];
    }
    if((temp[0]^temp[derivedSize-1])==derived[derivedSize-1])
    {
        free(temp);
        return true;
    }
    temp[0]=1;
    for(i=1;i<derivedSize;i++)
    {
        temp[i]=temp[i-1]^derived[i-1];
    }
    if((temp[0]^temp[derivedSize-1])==derived[derivedSize-1])
    {
        free(temp);
        return true;
    }
    free(temp);
    return false;
}
