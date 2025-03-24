#include <stdio.h>
#include <stdlib.h>

int findNumberOfLIS(int* nums, int numsSize)
{
    if(numsSize==0)
    {
        return 0;
    }
    int i,j,max=1,result=0;
    int* list=(int*)malloc(numsSize*sizeof(int));
    int* count=(int*)malloc(numsSize*sizeof(int));
    for(i=0;i<numsSize;i++)
    {
        list[i]=1;
        count[i]=1;
    }
    for(i=0;i<numsSize;i++)
    {
        for(j=0;j<i;j++)
        {
            if(nums[i]>nums[j])
            {
                if(list[j]+1>list[i])
                {
                    list[i]=list[j]+1;
                    count[i]=count[j];
                }
                else if(list[j]+1==list[i])
                {
                    count[i]+=count[j];
                }
            }
        }
    }
    for(i=0;i<numsSize;i++)
    {
        if(list[i]>max)
        {
            max=list[i];
            result=count[i];
        }
        else if(list[i]==max)
        {
            result+=count[i];
        }
    }
    free(list);
    free(count);
    return result;
}
