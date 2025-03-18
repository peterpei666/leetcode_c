#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool backtrack(int* nums,bool* used,int size,int index,int k,int target,int current)
{
    if(k==0)
    {
        return true;
    }
    if(current==target)
    {
        return backtrack(nums,used,size,0,k-1,target,0);
    }
    int i;
    for(i=index;i<size;i++)
    {
        if(used[i]==true||current+nums[i]>target)
        {
            continue;
        }
        used[i]=true;
        if(backtrack(nums,used,size,i+1,k,target,current+nums[i]))
        {
            return true;
        }
        used[i]=false;
    }
    return false;
}

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *b-*a;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k)
{
    int i,sum=0;
    for(i=0;i<numsSize;i++)
    {
        sum+=nums[i];
    }
    if(sum%k)
    {
        return false;
    }
    sum/=k;
    qsort(nums,numsSize,sizeof(int),compare);
    bool* used=(bool*)malloc(numsSize*sizeof(bool));
    memset(used,false,numsSize);
    bool result=backtrack(nums,used,numsSize,0,k,sum,0);
    free(used);
    return result;
}
