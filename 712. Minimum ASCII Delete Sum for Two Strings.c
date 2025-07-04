#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int min(int a,int b)
{
    return a<b?a:b;
}

int minimumDeleteSum(char* s1, char* s2)
{
    int i,j,prev,temp;
    int m=(int)strlen(s1);
    int n=(int)strlen(s2);
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+s2[i-1];
    }
    for(i=1;i<=m;i++)
    {
        prev=dp[0];
        dp[0]+=s1[i-1];
        for(j=1;j<=n;j++)
        {
            temp=dp[j];
            if(s1[i-1]==s2[j-1])
            {
                dp[j]=prev;
            }
            else
            {
                dp[j]=min(dp[j]+s1[i-1],dp[j-1]+s2[j-1]);
            }
            prev=temp;
        }
    }
    return dp[n];
}
