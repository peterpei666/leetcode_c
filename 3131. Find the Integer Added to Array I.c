#include <stdio.h>
#include <stdlib.h>

inline int mini(int a,int b)
{
    return a<b?a:b;
}

int addedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int i,m1,m2;
    m1=10000;
    m2=10000;
    for(i=0;i<nums1Size;i++)
    {
        m1=mini(m1,nums1[i]);
        m2=mini(m2,nums2[i]);
    }
    return m2-m1;
}
