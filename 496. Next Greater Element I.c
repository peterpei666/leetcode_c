#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    if(nums1Size==0)
    {
        *returnSize=0;
        return NULL;
    }
    int i,top=0;
    int* next=(int*)malloc(nums1Size*sizeof(int));
    int table[10001];
    int stack[1001];
    stack[0]=nums2[nums2Size-1];
    top++;
    for(i=0;i<10001;i++)
    {
        table[i]=-1;
    }
    for(i=nums2Size-2;i>=0;i--)
    {
        while(top>=0&&stack[top]<=nums2[i])
        {
            top--;
        }
        if(top>=0)
        {
            table[nums2[i]]=stack[top];
        }
        top++;
        stack[top]=nums2[i];
    }
    for(i=0;i<nums1Size;i++)
    {
        next[i]=table[nums1[i]];
    }
    *returnSize=nums1Size;
    return next;
}
