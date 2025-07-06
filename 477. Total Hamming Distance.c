#include <stdio.h>
#include <stdlib.h>

int totalHammingDistance(int* nums, int n)
{
    int i,j,temp,sum=0;
    int bit[32]={0};
    for(i=0;i<n;i++)
    {
        temp=nums[i];
        for(j=0;temp;j++,temp>>=1)
        {
            if(temp&1)
            {
                bit[j]++;
            }
        }
    }
    for(i=0;i<32;i++)
    {
        sum+=bit[i]*(n-bit[i]);
    }
    return sum;
}
