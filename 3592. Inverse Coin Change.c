#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findCoins(int* numWays, int n, int* returnSize)
{
    int i,j,k=0;
    int* ret=(int*)malloc(n*sizeof(int));
    int target[n+1];
    int dp[n+1];
    target[0]=1;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++)
    {
        target[i]=numWays[i-1];
    }
    dp[0]=1;
    for(i=1;i<=n;i++)
    {
        if(target[i]==dp[i])
        {
            continue;
        }
        if(target[i]==dp[i]+1)
        {
            ret[k]=i;
            k++;
            for(j=i;j<=n;j++)
            {
                dp[j]=dp[j]+dp[j-i];
            }
        }
        else
        {
            *returnSize=0;
            return NULL;
        }
    }
    *returnSize=k;
    return ret;
}
