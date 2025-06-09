#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

inline bool valid(long long x)
{
    return (x&(x-1))==0;
}

inline bool last(int list[])
{
    int i;
    for(i=0;i<10;i++)
    {
        if(list[i])
        {
            return false;
        }
    }
    return true;
}

bool dfs(long long cur,int list[],bool first)
{
    int i;
    if(first)
    {
        for(i=1;i<=9;i++)
        {
            if(list[i])
            {
                list[i]--;
                if(dfs(i,list,false))
                {
                    return true;
                }
                list[i]++;
            }
        }
    }
    else
    {
        if(last(list)&&valid(cur))
        {
            return true;
        }
        for(i=0;i<=9;i++)
        {
            if(list[i])
            {
                cur*=10;
                cur+=i;
                list[i]--;
                if(dfs(cur,list,false))
                {
                    return true;
                }
                list[i]++;
                cur/=10;
            }
        }
    }
    return false;
}

bool reorderedPowerOf2(int n)
{
    if(n==0)
    {
        return false;
    }
    int list[10];
    memset(list,0,sizeof(list));
    while(n)
    {
        list[n%10]++;
        n/=10;
    }
    return dfs(0,list,true);
}
