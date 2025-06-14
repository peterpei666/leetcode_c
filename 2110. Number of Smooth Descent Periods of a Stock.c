#include <stdio.h>
#include <stdlib.h>

long long getDescentPeriods(int* prices, int n)
{
    int i,j;
    long long ans=1;
    for(i=1,j=0;i<n;i++)
    {
        if(prices[i]!=prices[i-1]-1)
        {
            j=i;
        }
        ans+=i-j+1;
    }
    return ans;
}
