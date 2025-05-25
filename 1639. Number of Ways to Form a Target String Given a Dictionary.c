#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t,m;
const int mod=1e9+7;

long long build(char* target,int widx,int tidx,int freq[][26],long long dp[][t])
{
    if(tidx==t)
    {
        return 1;
    }
    if(widx==m||m-widx<t-tidx)
    {
        return 0;
    }
    if(dp[widx][tidx]!=-1)
    {
        return dp[widx][tidx];
    }
    long long way=0;
    way+=build(target,widx+1,tidx,freq,dp);
    way+=freq[widx][target[tidx]-'a']*build(target,widx+1,tidx+1,freq,dp);
    dp[widx][tidx]=way%mod;
    return dp[widx][tidx];
}

int numWays(char** words, int n, char* target)
{
    int i,j;
    m=(int)strlen(words[0]);
    t=(int)strlen(target);
    long long dp[m][t];
    int freq[m][26];
    memset(dp,-1,sizeof(dp));
    memset(freq,0,sizeof(freq));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            freq[j][words[i][j]-'a']++;
        }
    }
    return (int)build(target,0,0,freq,dp);
}
