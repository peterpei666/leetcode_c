#include <stdio.h>
#include <stdlib.h>

int findMin(int* nums, int n)
{
    int l=0,r=n-1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(nums[l]==nums[r]&&nums[l]==nums[mid])
        {
            l++;
            r--;
            continue;
        }
        if(nums[mid]>nums[r])
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    return nums[l];
}
