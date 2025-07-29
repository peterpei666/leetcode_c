#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char dp[2000][2000];

bool dfs(int i,int j,char* s, char* p)
{
    if(i<0&&j<0)
    {
        return true;
    }
    if(j<0)
    {
        return false;
    }
    if(i<0)
    {
        for(int k=0;k<=j;k++)
        {
            if(p[k]!='*')
            {
                return false;
            }
        }
        return true;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(p[j]==s[i]||p[j]=='?')
    {
        return dp[i][j]=dfs(i-1,j-1,s,p);
    }
    else if(p[j]=='*')
    {
        return dp[i][j]=dfs(i,j-1,s,p)||dfs(i-1,j,s,p);
    }
    return dp[i][j]=false;
}

bool isMatch(char* s, char* p)
{
    memset(dp,-1,sizeof(dp));
    int m=(int)strlen(s);
    int n=(int)strlen(p);
    return dfs(m-1,n-1,s,p);
}
