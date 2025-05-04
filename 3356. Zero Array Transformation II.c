#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool form(int* nums,int numsSize,int** queries,int queriesSize,int k)
{
    int i,sum=0;
    int* dif=(int*)calloc(sizeof(int),numsSize+1);
    for(i=0;i<k;i++)
    {
        dif[queries[i][0]]-=queries[i][2];
        dif[queries[i][1]+1]+=queries[i][2];
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

int minZeroArray(int* nums,int numsSize,int** queries,int queriesSize, int* queriesColSize)
{
    int l=0,r=queriesSize,mid;
    if(form(nums,numsSize,queries,queriesSize,r)==false)
    {
        return -1;
    }
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(form(nums,numsSize,queries,queriesSize,mid))
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return l;
}
