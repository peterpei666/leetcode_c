#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int i,j=0,size=numsSize;
    bool* found=(bool*)malloc(sizeof(bool)*numsSize);
    memset(found,false,numsSize);
    for(i=0;i<numsSize;i++)
    {
        if(found[nums[i]-1]==false)
        {
            found[nums[i]-1]=true;
            size--;
        }
    }
    if(size==0)
    {
        free(found);
        *returnSize=0;
        return NULL;
    }
    else
    {
        int* ret=(int*)malloc(sizeof(int)*size);
        for(i=0;i<numsSize;i++)
        {
            if(found[i]==false)
            {
                ret[j]=i+1;
                j++;
            }
        }
        free(found);
        *returnSize=size;
        return ret;
    }
}
