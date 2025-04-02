#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

inline long long max(long long a,long long b)
{
    return a>b?a:b;
}

int maxSum(int* nums1,int nums1Size,int* nums2,int nums2Size)
{
	int x=0,y=0;
	long long sum1=0,sum2=0;
	long long current=0;
	while(x<nums1Size||y<nums2Size)
	{
		if(x<nums1Size&&(y>=nums2Size||nums1[x]<nums2[y]))
        {
            sum1+=nums1[x];
            x++;
        }
        else if(y<nums2Size&&(x>=nums1Size||nums2[y]<nums1[x]))
        {
            sum2+=nums2[y];
            y++;
        }
        else
        {
            current+=max(sum1,sum2);
            current%=MOD;
            current+=nums1[x];
            current%=MOD;
            x++;
            y++;
            sum1=0;
            sum2=0;
        }
	}
    current+=max(sum1,sum2);
    current%=MOD;
    return (int)current;
}
