#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numWays(char* s)
{
    const int mod=1e9+7;
    int i,cnt=0,cnt1;
    int n1=1,n2=1;
    int n=(int)strlen(s);
    for(i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            cnt++;
        }
    }
    if(cnt==0)
    {
        return (long long)(n-1)*(n-2)/2%mod;
    }
    if(cnt%3)
    {
        return 0;
    }
    cnt/=3;
    for(i=0,cnt1=0;i<n&&cnt1<=cnt;i++)
    {
        if(s[i]=='1')
        {
            cnt1++;
        }
        if(s[i]=='0'&&cnt1==cnt)
        {
            n1++;
        }
    }
    for(i=n-1,cnt1=0;i>=0&&cnt1<=cnt;i--)
    {
        if(s[i]=='1')
        {
            cnt1++;
        }
        if(s[i]=='0'&&cnt1==cnt)
        {
            n2++;
        }
    }
    return (long long)n1*n2%mod;
}
