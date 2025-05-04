#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize)
{
    int i,sum=0;
    int* dif=(int*)calloc(sizeof(int),numsSize+1);
    for(i=0;i<queriesSize;i++)
    {
        dif[queries[i][0]]--;
        dif[queries[i][1]+1]++;
    }
    for(i=0;i<numsSize;i++)
    {
        sum+=dif[i];
        if(nums[i]+sum>0)
        {
            return false;
        }
    }
    return true;
}
