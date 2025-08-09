#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int n)
{
    int ans=0,cur=prices[0];
    for(int i=1;i<n;i++)
    {
        if(prices[i]>cur)
        {
            ans+=prices[i]-cur;
        }
        cur=prices[i];
    }
    return ans;
}
