#include <stdio.h>
#include <stdlib.h>

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

int partitionArray(int* nums, int numsSize, int k)
{
    int i,m=0,temp;
    qsort(nums,numsSize,sizeof(int),compare);
    for(i=0;i<numsSize;i++)
    {
        m++;
        temp=nums[i];
        while(i+1<numsSize&&nums[i+1]<=temp+k)
        {
            i++;
        }
    }
    return m;
}
