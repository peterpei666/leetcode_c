#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

int search(int* nums, int numsSize, long long target)
{
    int p;
    int left,mid,right;
    left=0;
    right=numsSize-1;
    while(left<right)
    {
        mid=(left+right)/2;
        if(nums[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            right=mid;
        }
    }
    return left;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize)
{
    
    int p,i;
    long long target;
    int* list=(int*)malloc(spellsSize*sizeof(int));
    qsort(potions,potionsSize,sizeof(int),compare);
    for(i=0;i<spellsSize;i++)
    {
        if(success%spells[i])
        {
            target=success/spells[i]+1;
        }
        else
        {
            target=success/spells[i];
        }
        if(target>potions[potionsSize-1])
        {
            list[i]=0;
            continue;
        }
        p=search(potions,potionsSize,target);
        list[i]=potionsSize-p;
    }
    *returnSize=spellsSize;
    return list;
}
