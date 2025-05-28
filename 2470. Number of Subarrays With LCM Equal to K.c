#include <stdio.h>
#include <stdlib.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

inline int min(int a,int b)
{
    return a<b?a:b;
}

int lcm(int a,int b,int k)
{
    int m1=max(a,b);
    int m2=min(a,b);
    for(int i=1;i<=m2;i++)
    {
        if(i*m1>k)
        {
            break;
        }
        if(i*m1%m2==0)
        {
            return i*m1;
        }
    }
    return k+1;
}

int subarrayLCM(int* nums, int n, int k)
{
    int i,j,cnt=0;
    for(i=0;i<n;i++)
    {
        int cur=nums[i];
        for(j=i;j<n;j++)
        {
            cur=lcm(cur,nums[j],k);
            if(cur>k)
            {
                break;
            }
            if(cur==k)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
