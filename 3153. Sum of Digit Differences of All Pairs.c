#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long countdif(int* list,int size)
{
    int i;
    long long count[10]={0};
    long long res=0;
    for(i=0;i<size;i++)
    {
        count[list[i]]++;
    }
    for(i=0;i<10;i++)
    {
        res+=count[i]*(size-count[i]);
    }
    return res/2;
}

long long sumDigitDifferences(int* nums, int numsSize)
{
    int i;
    long long count=0;
    int* current=(int*)malloc(sizeof(int)*numsSize);
    int* next=(int*)malloc(sizeof(int)*numsSize);
    int* temp;
    memcpy(current,nums,sizeof(int)*numsSize);
    while(current[0])
    {
        for(i=0;i<numsSize;i++)
        {
            next[i]=current[i]/10;
            current[i]%=10;
        }
        count+=countdif(current,numsSize);
        temp=next;
        next=current;
        current=temp;
    }
    free(current);
    free(next);
    return count;
}
