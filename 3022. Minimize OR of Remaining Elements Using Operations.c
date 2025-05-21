#include <stdio.h>
#include <stdlib.h>

int minOrAfterOperations(int* nums,int n,int k)
{
	int i,j,mask=0;
	int need,res;
	for(i=29;i>=0;i--)
	{
		mask|=1<<i;
		need=0;
		res=0;
		for(j=0;j<n;j++)
		{
			if(res)
			{
				res&=nums[j];
				need++;		
			}
			else if(nums[j]&mask)
			{
				res=nums[j]&mask;
			}
		}
		if(res)
		{
			need++;
		}
		if(need>k)
		{
			mask-=1<<i;
		}
	}
	return (1<<30)-mask-1;
}