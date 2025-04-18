#include <stdio.h>
#include <stdlib.h>

inline int mini(int a,int b)
{
    return a>b?b:a;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int i,j;
    int count1[1001]={0};
    int count2[1001]={0};
    int* ret=(int*)malloc(sizeof(int)*mini(nums1Size,nums2Size));
    for(i=0;i<nums1Size;i++)
    {
        count1[nums1[i]]++;
    }
    for(i=0;i<nums2Size;i++)
    {
        count2[nums2[i]]++;
    }
    for(i=0,j=0;i<=1000;i++)
    {
        if(count1[i]&&count2[i])
        {
            ret[j]=i;
            j++;
        }
    }
    *returnSize=j;
    return ret;
}

