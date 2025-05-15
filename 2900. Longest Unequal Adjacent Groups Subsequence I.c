#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** getLongestSubsequence(char** words, int n, int* groups, int groupsSize, int* returnSize)
{
    int i,j,m=0,p=0;
    int dp[n];
    int next[n];
    for(i=0;i<n;i++)
    {
        dp[i]=1;
        next[i]=-1;
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=i+1;j<n;j++)
        {
            if(groups[i]!=groups[j]&&dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
                next[i]=j;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(dp[i]>m)
        {
            m=dp[i];
            p=i;
        }
    }
    char** ret=(char**)malloc(sizeof(char*)*m);
    i=0;
    while(p!=-1)
    {
        ret[i]=words[p];
        i++;
        p=next[p];
    }
    *returnSize=m;
    return ret;
}
