#include <stdio.h>
#include <stdlib.h>

int* sumEvenAfterQueries(int* nums, int n, int** queries, int m, int* queriesColSize, int* returnSize)
{
    int i,sum=0;
    int* ret=(int*)malloc(sizeof(int)*m);
    for(i=0;i<n;i++)
    {
        if(nums[i]%2==0)
        {
            sum+=nums[i];
        }
    }
    for(i=0;i<m;i++)
    {
        if(nums[queries[i][1]]%2==0)
        {
            sum-=nums[queries[i][1]];
        }
        nums[queries[i][1]]+=queries[i][0];
        if(nums[queries[i][1]]%2==0)
        {
            sum+=nums[queries[i][1]];
        }
        ret[i]=sum;
    }
    *returnSize=m;
    return ret;
}
