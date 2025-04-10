#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long long dp[35][2];

long long solve(int tight,int index,char* t,char* s,int limit)
{
    int lent=(int)strlen(t);
    int lens=(int)strlen(s);
    int max,suffix,i,sindex,ntight;
    long long ans=0;
    if(index==lent)
    {
        return 1;
    }
    if(dp[index][tight]!=-1)
    {
        return dp[index][tight];
    }
    max=(tight?t[index]-'0':limit);
    if(max>limit)
    {
        max=limit;
    }
    suffix=lent-lens;
    for(i=0;i<=max;i++)
    {
        if(index>=suffix)
        {
            sindex=index-suffix;
            if(i!=s[sindex]-'0')
            {
                continue;
            }
        }
        ntight=(tight&&(i==(t[index]-'0')));
        ans+=solve(ntight,index+1,t,s,limit);
    }
    dp[index][tight]=ans;
    return ans;
}

long long numberOfPowerfulInt(long long start, long long finish, int limit, char* s)
{
    char t[35],t1[35];
    long long counts=0,countf=0;
    int lent,lent1,lens,i,j;
    sprintf(t,"%lld",finish);
    sprintf(t1,"%lld",start-1);
    lent=(int)strlen(t);
    lent1=(int)strlen(t1);
    lens=(int)strlen(s);
    if(lent<lens)
    {
        countf=0;
    }
    else
    {
        for(i=0;i<lent;i++)
        {
            for(j=0;j<2;j++)
            {
                dp[i][j]=-1;
            }
        }
        countf=solve(1,0,t,s,limit);
    }
    if(lent1<lens)
    {
        counts=0;
    }
    else
    {
        for(i=0;i<lent1;i++)
        {
            for(j=0;j<2;j++)
            {
                dp[i][j]=-1;
            }
        }
        counts=solve(1,0,t1,s,limit);
    }
    return countf-counts;
}
