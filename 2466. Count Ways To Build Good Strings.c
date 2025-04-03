#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int countGoodStrings(int low, int high, int zero, int one)
{
    int i,res=0;
    int* dp=(int*)calloc(high+1,sizeof(int));
    dp[0]=1;
    for(i=1;i<=high;i++)
    {
        if(i>=zero)
        {
            dp[i]+=dp[i-zero];
            dp[i]%=MOD;
        }
        if(i>=one)
        {
            dp[i]+=dp[i-one];
            dp[i]%=MOD;
        }
        if(i>=low)
        {
            res+=dp[i];
            res%=MOD;
        }
    }
    free(dp);
    return res;
}
