#include <stdio.h>
#include <stdlib.h>

int numTrees(int n)
{
    int i,j,temp;
    int* dp=(int*)calloc(n+1,sizeof(int));
    dp[0]=1;
    dp[1]=1;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            dp[i]+=dp[j-1]*dp[i-j];
        }
    }
    temp=dp[n];
    free(dp);
    return temp;
}
