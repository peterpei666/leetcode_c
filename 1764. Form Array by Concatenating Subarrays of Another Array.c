#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool canChoose(int** groups, int groupsSize, int* groupsColSize, int* nums, int numsSize)
{
    int i,j;
    for(i=0,j=0;i<numsSize;i++)
    {
        if(nums[i]==groups[j][0])
        {
            if(numsSize-i>=groupsColSize[j])
            {
                if(memcmp(nums+i,groups[j],sizeof(int)*groupsColSize[j])==0)
                {
                    i+=groupsColSize[j]-1;
                    j++;
                    if(j==groupsSize)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
