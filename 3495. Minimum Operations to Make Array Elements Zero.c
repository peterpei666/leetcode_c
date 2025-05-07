#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long count(int x)
{
    if(x==0)
    {
        return 0;
    }
    int n=-1,t=x;
    long long ret,cur;
    while(t)
    {
        t>>=2;
        n++;
    }
    ret=(long long)x*(n+1);
    cur=1<<2*n;
    while(cur)
    {
        ret-=cur-1;
        cur>>=2;
    }
    return ret;
}

long long minOperations(int** queries, int queriesSize, int* queriesColSize)
{
    int i;
    long long ret=0,temp;
    for(i=0;i<queriesSize;i++)
    {
        temp=count(queries[i][1])-count(queries[i][0]-1);
        ret+=temp/2+temp%2;
    }
    return ret;
}
