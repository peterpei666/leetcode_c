#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}

int minimizeConcatenatedLength(char** words, int n)
{
    int i,j,k;
    int len,total,ans,cur;
    int dp[2][26][26];
    memset(dp,-1,sizeof(dp));
    total=(int)strlen(words[0]);
    dp[0][words[0][0]-'a'][words[0][total-1]-'a']=0;
    ans=0;
    for(k=1;k<n;k++)
    {
        len=(int)strlen(words[k]);
        total+=len;
        cur=k&1;
        memset(dp[cur],-1,sizeof(dp[cur]));
        for(i=0;i<26;i++)
        {
            for(j=0;j<26;j++)
            {
                if(dp[cur^1][i][j]==-1)
                {
                    continue;
                }
                dp[cur][words[k][0]-'a'][j]=max(dp[cur][words[k][0]-'a'][j],dp[cur^1][i][j]+(words[k][len-1]-'a'==i));
                dp[cur][i][words[k][len-1]-'a']=max(dp[cur][i][words[k][len-1]-'a'],dp[cur^1][i][j]+(words[k][0]-'a'==j));
                ans=max(ans,max(dp[cur][words[k][0]-'a'][j],dp[cur][i][words[k][len-1]-'a']));
            }
        }
    }
    return total-ans;
}
