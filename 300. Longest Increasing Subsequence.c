#include <stdio.h>
#include <stdlib.h>

int lengthOfLIS(int* nums, int numsSize)
{
    int i,j,max=1;
    int* list=(int*)malloc(numsSize*sizeof(int));
    for(i=0;i<numsSize;i++)
    {
        list[i]=1;
        for(j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                list[i]=(list[i]>list[j]+1)?list[i]:list[j]+1;
            }
        }
        if(max<list[i])
        {
            max=list[i];
        }
    }
    free(list);
    return max;
}
