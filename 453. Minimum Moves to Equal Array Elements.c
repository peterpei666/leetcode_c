#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

inline int min(int a,int b)
{
	return a<b?a:b;
}

int minMoves(int* nums,int n)
{
	int m=INT_MAX;
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		m=min(m,nums[i]);
	}
	for(i=0;i<n;i++)
	{
		sum+=nums[i]-m;
	}
	return sum;
}
