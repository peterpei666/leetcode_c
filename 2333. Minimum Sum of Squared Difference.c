#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

inline int mini(int a,int b)
{
    return a<b?a:b;
}

long long minSumSquareDiff(int* nums1, int n, int* nums2, int nums2Size, int k1, int k2)
{
    int i;
    int k=k1+k2;
    int m=0;
    int dif[n];
    long long ret=0;
    for(int i=0;i<n;i++)
    {
        dif[i]=abs(nums1[i]-nums2[i]);
        m=maxi(dif[i],m);
    }
    int list[m+1];
    memset(list,0,sizeof(list));
    for(i=0;i<n;i++)
    {
        list[dif[i]]++;
    }
    for(i=m;i>0&&k;i--)
    {
        int temp=mini(k,list[i]);
        k-=temp;
        list[i]-=temp;
        list[i-1]+=temp;
    }
    for(i=1;i<=m;i++)
    {
        ret+=(long long)list[i]*i*i;
    }
    return ret;
}
