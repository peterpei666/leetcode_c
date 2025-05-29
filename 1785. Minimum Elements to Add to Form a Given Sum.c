#include <stdio.h>
#include <stdlib.h>

int minElements(int* nums, int n, int limit, int goal)
{
    int i,m;
    long long sum=0;
    for(i=0;i<n;i++)
    {
        sum+=nums[i];
    }
    sum=llabs(sum-goal);
    m=(int)(sum/limit);
    if(sum%limit)
    {
        m++;
    }
    return m;
}
