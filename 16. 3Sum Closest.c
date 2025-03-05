#include <stdio.h>
#include <stdlib.h>

int compare(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

int threeSumClosest(int* nums,int numsSize,int target)
{
    int i,current=2147483647,ans=0,left,right,sum;
    qsort(nums,numsSize,sizeof(int),compare);
    for(i=0;i<numsSize-2;i++)
    {
        left=i+1;
        right=numsSize-1;
        while(left<right)
        {
            sum=nums[i]+nums[left]+nums[right];
            if(abs(sum-target)<current)
            {
                current=abs(sum-target);
                ans=sum;
            }
            if(sum>target)
            {
                right--;
            }
            else if(sum<target)
            {
                left++;
            }
            else
            {
                return target;
            }
        }
    }
    return ans;
}
