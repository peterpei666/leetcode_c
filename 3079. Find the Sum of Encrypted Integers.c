#include <stdio.h>
#include <stdlib.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int encrypt(int x)
{
    int c=0,m=0;
    while(x)
    {
        c++;
        m=maxi(m,x%10);
        x/=10;
    }
    while(c)
    {
        x*=10;
        x+=m;
        c--;
    }
    return x;
}

int sumOfEncryptedInt(int* nums, int numsSize)
{
    int sum=0,i;
    for(i=0;i<numsSize;i++)
    {
        sum+=encrypt(nums[i]);
    }
    return sum;
}
