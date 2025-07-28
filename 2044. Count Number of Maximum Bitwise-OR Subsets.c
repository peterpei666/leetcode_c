#include <stdio.h>
#include <stdlib.h>

int countMaxOrSubsets(int* nums, int n)
{
    int max=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        max|=nums[i];
    }
    for(int mask=1;mask<(1<<n);mask++)
    {
        int temp=0;
        for(int i=0;(1<<i)<=mask;i++)
        {
            if(mask&(1<<i))
            {
                temp|=nums[i];
            }
        }
        if(temp==max)
        {
            cnt++;
        }
        
    }
    return cnt;
}
