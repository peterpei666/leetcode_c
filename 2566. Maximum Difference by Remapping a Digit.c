#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

int minMaxDifference(int num)
{
    int temp=num;
    int l=INT_MAX;
    int r=INT_MIN;
    int i,t;
    int list[10]={0};
    for(t=1;temp;t*=10)
    {
        list[temp%10]+=t;
        temp/=10;
    }
    for(i=0;i<10;i++)
    {
        l=min(l,num-list[i]*i);
        r=max(r,num+list[i]*(9-i));
    }
    return r-l;
}
