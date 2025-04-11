#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize)
{
    int i,j,current,t;
    for(i=0,j=0;i<numsSize;i++)
    {
        current=nums[i];
        t=1;
        while(i+1<numsSize&&nums[i+1]==current)
        {
            i++;
            t++;
        }
        if(t==1)
        {
            nums[j]=current;
            j++;
        }
        else
        {
            nums[j]=current;
            nums[j+1]=current;
            j+=2;
        }
    }
    return j;
}
