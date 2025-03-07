#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val)
{
    int i,j=0,capacity=1;
    int* list=(int*)malloc(capacity*sizeof(int));
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]!=val)
        {
            capacity++;
            list=(int*)realloc(list,capacity*sizeof(int));
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
