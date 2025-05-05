#include <stdio.h>
#include <stdlib.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maximumsSplicedArray(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int n=nums1Size,i;
    int sum1=0,sum2=0;
    int sumA=0,sumB=0;
    int dif1=0,dif2=0;
    int* temp1=(int*)malloc(sizeof(int)*n);
    int* temp2=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        sum1+=nums1[i];
        sum2+=nums2[i];
        temp1[i]=nums2[i]-nums1[i];
        temp2[i]=nums1[i]-nums2[i];
    }
    for(int i=0;i<n;i++)
    {
        sumA+=temp1[i];
        sumB+=temp2[i];
        dif1=maxi(dif1,sumA);
        dif2=maxi(dif2,sumB);
        sumA=maxi(0,sumA);
        sumB=maxi(0,sumB);
    }
    free(temp1);
    free(temp2);
    return maxi(sum1+dif1,sum2+dif2);
}
