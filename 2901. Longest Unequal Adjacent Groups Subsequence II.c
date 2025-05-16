#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** getWordsInLongestSubsequence(char** words, int n, int* groups, int groupsSize, int* returnSize)
{
    int i,j,d,m,p;
    int dp[n];
    int next[n];
    int len[n];
    long long mask;
    long long masks[n];
    for(i=0;i<n;i++)
    {
        mask=0;
        len[i]=(int)strlen(words[i]);
        for(j=0;j<len[i];j++)
        {
            mask|=((long long)(words[i][j]-'a'))<<(5*j);
        }
        masks[i]=mask;
        dp[i]=1;
        next[i]=-1;
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=i+1;j<n;j++)
        {
            if(groups[i]!=groups[j]&&len[i]==len[j]&&dp[j]+1>dp[i])
            {
                mask=masks[i]^masks[j];
                d=0;
                while(mask)
                {
                    if(mask&31)
                    {
                        d++;
                    }
                    mask>>=5;
                }
                if(d==1)
                {
                    dp[i]=dp[j]+1;
                    next[i]=j;
                }
            }
        }
    }
    m=0;
    p=0;
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
