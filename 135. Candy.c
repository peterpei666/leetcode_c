#include <stdio.h>
#include <stdlib.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int candy(int* ratings,int n)
{
    int i,cnt=0;
    int list[n];
    for(i=0;i<n;i++)
    {
        list[i]=1;
    }
    for(i=1;i<n;i++)
    {
        if(ratings[i]>ratings[i-1])
        {
            list[i]=list[i-1]+1;
        }
    }
    for(i=n-2;i>=0;i--)
    {
        if(ratings[i]>ratings[i+1])
        {
            list[i]=max(list[i],list[i+1]+1);
        }
    }
    for(i=0;i<n;i++)
    {
        cnt+=list[i];
    }
    return cnt;
}
