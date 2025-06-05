#include <stdio.h>
#include <stdlib.h>

int superPow(int a, int* b, int n)
{
    const int mod=1337;
    int i,j,temp=a%mod,t=a%mod;
    int ans=1;
    for(i=n-1;i>=0;i--)
    {
        while(b[i])
        {
            b[i]--;
            ans=(ans*temp)%mod;
        }
        for(j=0;j<9;j++)
        {
            temp=(temp*t)%mod;
        }
        t=temp;
    }
    return ans;
}
