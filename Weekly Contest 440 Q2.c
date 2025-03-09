#include <stdio.h>
#include <stdlib.h>

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *b-*a;
}

long long* findMaxSum(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize)
{
    int i,j,n;
    long long* ans=(long long*)calloc(nums1Size,sizeof(long long));
    for(i=0;i<nums1Size;i++)
    {
        int* temp=(int*)calloc(k,sizeof(int));
        for(j=0;j<nums1Size;j++)
        {
            if(nums1[j]<nums1[i]&&nums2[j]>temp[k-1])
            {
                temp[k-1]=nums2[j];
                qsort(temp,k,sizeof(int),compare);
            }
        }
        for(n=0;n<k;n++)
        {
            ans[i]+=(long long)temp[n];
        }
        free(temp);
    }
    *returnSize=nums1Size;
    return ans;
}
