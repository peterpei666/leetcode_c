#include <stdio.h>
#include <stdlib.h>

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize)
{
    int i,j,max=1,mp=0;
    int* dp=(int*)malloc(sizeof(int)*numsSize);
    qsort(nums,numsSize,sizeof(int),compare);
    for(i=0;i<numsSize;i++)
    {
        dp[i]=1;
    }
    for(i=1;i<numsSize;i++)
    {
        for(j=0;j<i;j++)
        {
            if(nums[i]%nums[j]==0)
            {
                if(dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    if(dp[i]>max)
                    {
                        max=dp[i];
                        mp=i;
                    }
                }
            }
        }
    }
    int* subset=(int*)malloc(sizeof(int)*max);
    subset[max-1]=nums[mp];
    j=max-1;
    for(i=mp-1;i>=0;i--)
    {
        if(j>0&&subset[j]%nums[i]==0&&dp[mp]==dp[i]+1)
        {
            j--;
            subset[j]=nums[i];
            mp=i;
        }
        if(j==0)
        {
            break;
        }
    }
    *returnSize=max;
    free(dp);
    return subset;
}
