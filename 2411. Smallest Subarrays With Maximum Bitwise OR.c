#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* smallestSubarrays(int* nums, int n, int* returnSize)
{
    int list[n];
    list[n-1]=nums[n-1];
    for(int i=n-2;i>=0;i--)
    {
        list[i]=nums[i]|list[i+1];
    }
    int* ans=(int*)malloc(n*sizeof(int));
    int bit[32];
    int temp=nums[0];
    memset(bit,-1,sizeof(bit));
    for(int k=0;nums[0]>=(1<<k);k++)
    {
        if(nums[0]&(1<<k))
        {
            bit[k]=0;
        }
    }
    for(int i=0,j=1;i<n;i++)
    {
        while((j<n&&temp<list[i])||j<=i)
        {
            temp|=nums[j];
            for(int k=0;nums[j]>=(1<<k);k++)
            {
                if(nums[j]&(1<<k))
                {
                    bit[k]=j;
                }
            }
            j++;
        }
        ans[i]=j-i;
        for(int k=0;k<32;k++)
        {
            if(bit[k]==i)
            {
                temp-=1<<k;
            }
        }
    }
    *returnSize=n;
    return ans;
}
