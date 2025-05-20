#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int lastStoneWeightII(int* stones, int n)
{
    int i,j;
    int sum=0;
    bool dp[3001];
    dp[0]=true;
    for(i=0;i<n;i++)
    {
        for(j=sum;j>=0;j--)
        {
            if(dp[j])
            {
                dp[j+stones[i]]=true;
            }
        }
        sum+=stones[i];
    }
    for(i=sum/2;i>=0;i--)
    {
        if(dp[i])
        {
            return sum-2*i;
        }
    }
    return 0;
}
