#include <stdio.h>
#include <stdlib.h>

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *b-*a;
}

int maxSum(int* nums, int numsSize)
{
    int list[101]={0},i=0,ans=0;
    qsort(nums,numsSize,sizeof(int),compare);
    if(nums[0]<=0)
    {
        return nums[0];
    }
    while(i<numsSize&&nums[i]>0)
    {
        if(list[nums[i]]==0)
        {
            ans+=nums[i];
            list[nums[i]]=1;
        }
        i++;
    }
    return ans;
}
