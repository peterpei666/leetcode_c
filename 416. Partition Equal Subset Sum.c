#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool canPartition(int* nums, int numsSize)
{
    int i,j,sum=0;
    for(i=0;i<numsSize;i++)
    {
        sum+=nums[i];
    }
    if(sum%2)
    {
        return false;
    }
    else
    {
        sum/=2;
        bool* list=(bool*)malloc((sum+1)*sizeof(bool));
        memset(list,false,sum+1);
        list[0]=true;
        for(i=0;i<numsSize;i++)
        {
            for(j=sum;j>=nums[i];j--)
            {
                list[j]=list[j]||list[j-nums[i]];
            }
            if(list[sum])
            {
                free(list);
                return true;
            }
        }
        free(list);
        return false;
    }
}
