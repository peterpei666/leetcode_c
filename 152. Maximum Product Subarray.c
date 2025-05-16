#include <stdio.h>
#include <stdlib.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maxProduct(int* nums, int n)
{
    int i,m,temp;
    m=-100;
    temp=1;
    for(i=0;i<n;i++)
    {
        temp*=nums[i];
        m=maxi(m,temp);
        if(temp==0)
        {
            temp=1;
        }
    }
    temp=1;
    for(i=n-1;i>=0;i--)
    {
        temp*=nums[i];
        m=maxi(m,temp);
        if(temp==0)
        {
            temp=1;
        }
    }
    return m;
}
