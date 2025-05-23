#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

int maxNumOfMarkedIndices(int* nums, int n)
{
    int i,j;
    qsort(nums,n,sizeof(int),cmp);
    for(i=0,j=n-n/2;j<n;j++)
    {
        if(2*nums[i]<=nums[j])
        {
            i++;
        }
    }
    return 2*i;
}
