#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize)
{
    int i,j,sum;
    int* result=(int*)malloc(queriesSize*sizeof(int));
    qsort(nums,numsSize,sizeof(int),compare);
    for(i=0;i<queriesSize;i++)
    {
        sum=0;
        for(j=0;j<numsSize&&sum+nums[j]<=queries[i];j++)
        {
            sum+=nums[j];
        }
        result[i]=j;
    }
    *returnSize=queriesSize;
    return result;
}
