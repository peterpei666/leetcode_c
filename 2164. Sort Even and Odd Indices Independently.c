#include <stdio.h>
#include <stdlib.h>

int cmp1(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

int cmp2(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *b-*a;
}

int* sortEvenOdd(int* nums, int numsSize, int* returnSize)
{
    int i;
    int odd=numsSize/2;
    int even=numsSize-odd;
    int* list1=(int*)malloc(sizeof(int)*odd);
    int* list2=(int*)malloc(sizeof(int)*even);
    for(i=0;i<numsSize;i++)
    {
        if(i&1)
        {
            list1[i>>1]=nums[i];
        }
        else
        {
            list2[i>>1]=nums[i];
        }
    }
    qsort(list1,odd,sizeof(int),cmp2);
    qsort(list2,even,sizeof(int),cmp1);
    for(i=0;i<numsSize;i++)
    {
        if(i&1)
        {
            nums[i]=list1[i>>1];
        }
        else
        {
            nums[i]=list2[i>>1];
        }
    }
    free(list1);
    free(list2);
    *returnSize=numsSize;
    return nums;
}
