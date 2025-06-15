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

int maxDiff(int num)
{
    int i,t,temp=num;
    int list[10]={0};
    int m1=INT_MIN,m2=INT_MAX;
    int top=num;
    for(t=1;temp;t*=10)
    {
        list[temp%10]+=t;
        temp/=10;
    }
    while(top>=10)
    {
        top/=10;
    }
    for(i=0;i<=9;i++)
    {
        m1=max(m1,num+(9-i)*list[i]);
        if(i==top)
        {
            m2=min(m2,num-(i-1)*list[i]);
        }
        else
        {
            m2=min(m2,num-i*list[i]);
        }
    }
    return m1-m2;
}
