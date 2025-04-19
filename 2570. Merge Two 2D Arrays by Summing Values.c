#include <stdio.h>
#include <stdlib.h>

int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, int* nums2ColSize, int* returnSize, int** returnColumnSizes)
{
    int i,j=0,count=0;
    int list[1000]={0};
    for(i=0;i<nums1Size;i++)
    {
        if(list[nums1[i][0]-1]==0)
        {
            count++;
        }
        list[nums1[i][0]-1]+=nums1[i][1];
    }
    for(i=0;i<nums2Size;i++)
    {
        if(list[nums2[i][0]-1]==0)
        {
            count++;
        }
        list[nums2[i][0]-1]+=nums2[i][1];
    }
    int** ret=(int**)malloc(sizeof(int*)*count);
    *returnColumnSizes=(int*)malloc(sizeof(int)*count);
    *returnSize=count;
    for(i=0;i<count;i++)
    {
        ret[i]=(int*)malloc(sizeof(int)*2);
        (*returnColumnSizes)[i]=2;
    }
    for(i=0,j=0;i<1000;i++)
    {
        if(list[i])
        {
            ret[j][0]=i+1;
            ret[j][1]=list[i];
            j++;
        }
    }
    return ret;
}
