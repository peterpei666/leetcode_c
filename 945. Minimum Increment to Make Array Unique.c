#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

int minIncrementForUnique(int* nums, int n)
{
    qsort(nums,n,sizeof(int),cmp);
    int sum=0,cur=nums[0];
    for(int i=1;i<n;i++)
    {
        if(nums[i]<cur+1)
        {
            sum+=cur+1-nums[i];
            cur++;
        }
        else
        {
            cur=nums[i];
        }
    }
    return sum;
}
