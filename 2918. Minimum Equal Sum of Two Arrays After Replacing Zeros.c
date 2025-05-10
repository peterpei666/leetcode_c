#include <stdio.h>
#include <stdlib.h>

long long minSum(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int i;
    long long sum1=0,count1=0;
    long long sum2=0,count2=0;
    for(i=0;i<nums1Size;i++)
    {
        if(nums1[i]==0)
        {
            count1++;
        }
        else
        {
            sum1+=nums1[i];
        }
    }
    for(i=0;i<nums2Size;i++)
    {
        if(nums2[i]==0)
        {
            count2++;
        }
        else
        {
            sum2+=nums2[i];
        }
    }
    if(count1==0&&count2==0)
    {
        return sum1==sum2?sum1:-1;
    }
    if(count1==0)
    {
        return sum2+count2<=sum1?sum1:-1;
    }
    if(count2==0)
    {
        return sum1+count1<=sum2?sum2:-1;
    }
    return sum1+count1>sum2+count2?sum1+count1:sum2+count2;
}
