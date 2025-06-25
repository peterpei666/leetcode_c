#include <stdio.h>
#include <stdlib.h>

long long count(int* nums1,int n1,int* nums2,int n2,long long target)
{
    int i,l,r,mid;
    long long cnt=0;
    long long temp;
    for(i=0;i<n1;i++)
    {
        if(nums1[i]==0)
        {
            if(target>=0)
            {
                cnt+=n2;
            }
            continue;
        }
        l=0;
        r=n2;
        while(l<r)
        {
            mid=(l+r)/2;
            temp=(long long)nums1[i]*nums2[mid];
            if(temp>target)
            {
                if(nums1[i]>0)
                {
                    r=mid;
                }
                else
                {
                    l=mid+1;
                }
            }
            else
            {
                if(nums1[i]>0)
                {
                    l=mid+1;
                }
                else
                {
                    r=mid;
                }
            }
        }
        if(nums1[i]>0)
        {
            cnt+=l;
        }
        else
        {
            cnt+=n2-l;
        }
    }
    return cnt;
}

long long kthSmallestProduct(int* nums1, int n1, int* nums2, int n2, long long k)
{
    long long l,r,mid;
    l=-1e10;
    r=1e10;
    while(l<r)
    {
        mid=(r-l)/2+l;
        if(count(nums1,n1,nums2,n2,mid)<k)
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    return l;
}
