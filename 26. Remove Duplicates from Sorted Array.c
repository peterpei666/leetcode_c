#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize)
{
    int i,j=0,capacity=10;
    int* list=(int*)malloc(capacity*sizeof(int));
    list[j]=nums[0];
    j++;
    for(i=1;i<numsSize;i++)
    {
        if(j>=capacity-2)
        {
            capacity+=10;
            list=(int*)realloc(list,capacity*sizeof(int));
        }
        if(nums[i]!=list[j-1])
        {
            list[j]=nums[i];
            j++;
        }
    }
    for(i=0;i<j;i++)
    {
        nums[i]=list[i];
    }
    return j;
}

