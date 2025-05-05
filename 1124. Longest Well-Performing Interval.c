#include <stdio.h>
#include <stdlib.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int longestWPI(int* hours, int hoursSize)
{
    int i,count=0,ret=0;
    int list[10001];
    for(i=0;i<10001;i++)
    {
        list[i]=-1;
    }
    for(i=0;i<hoursSize;i++)
    {
        count+=hours[i]>8?1:-1;
        if(count>0)
        {
            ret=i+1;
        }
        else
        {
            if(list[-count+1]==-1)
            {
                list[-count+1]=i;
            }
            if(list[-count+2]!=-1)
            {
                ret=maxi(ret,i-list[-count+2]);
            }
        }
    }
    return ret;
}
