#include <stdio.h>
#include <stdlib.h>

int minPatches(int* nums, int sz, int n)
{
    long long miss=1;
    int i=0,ans=0;
    while(miss<=n)
    {
        if(i<sz&&miss>=nums[i])
        {
            miss+=nums[i];
            i++;
        }
        else
        {
            miss<<=1;
            ans++;
        }
    }
    return ans;
}
