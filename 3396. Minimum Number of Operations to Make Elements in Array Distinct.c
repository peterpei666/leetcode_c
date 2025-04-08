#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int minimumOperations(int* nums, int numsSize)
{
    int i,count=0;
    bool* found=(bool*)malloc(sizeof(bool)*100);
    memset(found,false,100);
    for(i=numsSize;i>0;i--)
    {
        if(found[nums[i-1]-1]==false)
        {
            found[nums[i-1]-1]=true;
        }
        else
        {
            break;
        }
    }
    count=i/3;
    if(i%3)
    {
        count++;
    }
    free(found);
    return count;
}
