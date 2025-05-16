#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int dp[13][4096];
int m,n;

inline int mini(int a,int b)
{
    return a<b?a:b;
}

int dfs(int** cost,int minsz[13],int i,int mask)
{
    if(dp[i][mask])
    {
        return dp[i][mask]-1;
    }
    int j;
    int res=(i>=m)?0:INT_MAX;
    if(i>=m)
    {
        for(j=0;j<n;j++)
        {
            res+=minsz[j]*((mask&(1<<j))==0);
        }
    }
    else
    {
        for(j=0;j<n;j++)
        {
            res=mini(res,cost[i][j]+dfs(cost,minsz,i+1,mask|(1<<j)));
        }
    }
    dp[i][mask]=res+1;
    return res;
}

int connectTwoGroups(int** cost, int costSize, int* costColSize)
{
    int i,j;
    int minsz[13];
    memset(dp,0,sizeof(dp));
    m=costSize;
    n=costColSize[0];
    for(i=0;i<n;i++)
    {
        minsz[i]=INT_MAX;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            minsz[j]=mini(minsz[j],cost[i][j]);
        }
    }
    return dfs(cost,minsz,0,0);
}
