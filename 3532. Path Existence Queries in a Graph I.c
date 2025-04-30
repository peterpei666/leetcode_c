#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool* pathExistenceQueries(int n, int* nums, int numsSize, int maxDiff, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
    int i;
    int* group=(int*)malloc(sizeof(int)*n);
    bool* ret=(bool*)malloc(sizeof(bool)*queriesSize);
    group[0]=1;
    for(i=1;i<n;i++)
    {
        if(nums[i]-nums[i-1]<=maxDiff)
        {
            group[i]=group[i-1];
        }
        else
        {
            group[i]=group[i-1]+1;
        }
    }
    for(int i=0;i<queriesSize;i++)
    {
        ret[i]=(group[queries[i][0]]==group[queries[i][1]]);
    }
    *returnSize=queriesSize;
    free(group);
    return ret;
}
