#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

int minimumBeautifulSubstrings(char* s)
{
    int i,j,cur;
    int n=(int)strlen(s);
    int dp[n+1];
    dp[0]=0;
    for(i=1;i<=n;i++)
    {
        dp[i]=n+1;
    }
    for(i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            continue;;
        }
        for(j=i,cur=0;j<n;j++)
        {
            cur=cur*2+s[j]-'0';
            if(78125%cur==0)
            {
                dp[j+1]=min (dp[j+1],dp[i]+1);
            }
        }
    }
    return dp[n]>n?-1:dp[n];
}
