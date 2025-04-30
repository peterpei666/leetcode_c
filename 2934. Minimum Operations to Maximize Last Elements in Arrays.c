#include <stdio.h>
#include <stdlib.h>

inline int mini(int a,int b)
{
    return a<b?a:b;
}

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int minOperations(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int a=nums1[nums1Size-1],b=nums2[nums2Size-1];
    int m1=mini(a,b),m2=maxi(a,b);
    int c1=0,c2=1,i;
    for(i=0;i<nums1Size-1;i++)
    {
        if(m1<mini(nums1[i],nums2[i])||m2<maxi(nums1[i],nums2[i]))
        {
            return -1;
        }
        if(!(nums1[i]<=a&&nums2[i]<=b))
        {
            c1++;
        }
        if(!(nums1[i]<=b&&nums2[i]<=a))
        {
            c2++;
        }
    }
    return mini(c1,c2);
}
