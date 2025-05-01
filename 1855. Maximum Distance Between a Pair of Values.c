#include <stdio.h>
#include <stdlib.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int i,j=0,dis=0;
    for(i=0;i<nums1Size;i++)
    {
        j=maxi(j,i);
        while(j+1<nums2Size&&nums2[j+1]>=nums1[i])
        {
            j++;
        }
        dis=maxi(dis,j-i);
        if(j==nums2Size-1)
        {
            break;
        }
    }
    return dis;
}
