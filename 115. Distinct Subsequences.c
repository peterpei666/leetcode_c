#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dfs(int i,int j,int m,int n,char* s,char* t,int memo[m][n])
{
    if(j==n)
    {
        return 1;
    }
    if(m-i<n-j)
    {
        return 0;
    }
    if(memo[i][j]!=-1)
    {
        return memo[i][j];
    }
    if(s[i]==t[j])
    {
        return memo[i][j]=dfs(i+1,j+1,m,n,s,t,memo)+dfs(i+1,j,m,n,s,t,memo);
    }
    return memo[i][j]=dfs(i+1,j,m,n,s,t,memo);
};

int numDistinct(char* s,char* t)
{
    int m=(int)strlen(s);
    int n=(int)strlen(t);
    int memo[m][n];
    memset(memo,-1,sizeof(memo));
    return dfs(0,0,m,n,s,t,memo);
}
