#include <stdio.h>
#include <stdlib.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

inline int mini(int a,int b)
{
    return a<b?a:b;
}

int minMoves(int* nums, int numsSize, int limit)
{
    int i,ret=numsSize,cur=0,l,r,sum;
    int* dif=(int*)calloc(sizeof(int),2*limit+2);
    for(i=0;i<numsSize/2;i++)
    {
        l=mini(nums[i],nums[numsSize-i-1])+1;
        r=maxi(nums[i],nums[numsSize-i-1])+limit;
        sum=nums[i]+nums[numsSize-i-1];
        dif[2]+=2;
        dif[l]--;
        dif[sum]--;
        dif[r+1]++;
        dif[sum+1]++;
    }
    for(i=2;i<=limit*2;i++)
    {
        cur+=dif[i];
        ret=mini(ret,cur);
    }
    free(dif);
    return ret;
}
