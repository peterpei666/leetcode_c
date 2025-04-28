#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

int triangleNumber(int* nums, int numsSize)
{
    int i,j,k,ans=0;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(k=numsSize-1;k>=2;k--)
    {
        i=0;
        j=k-1;
        while(i<j)
        {
            if(nums[i]+nums[j]>nums[k])
            {
                ans+=j-i;
                j--;
            }
            else
            {
                i++;
            }
        }
    }
    return ans;
}
