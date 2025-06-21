#include <stdio.h>
#include <stdlib.h>

int valueAfterKSeconds(int n, int k)
{
    int i,j;
    const int mod=1e9+7;
    int list[2][n];
    for(i=0;i<n;i++)
    {
        list[0][i]=1;
    }
    for(i=1;i<=k;i++)
    {
        list[i%2][0]=list[(i-1)%2][0];
        for(j=1;j<n;j++)
        {
            list[i%2][j]=(list[i%2][j-1]+list[(i-1)%2][j])%mod;
        }
    }
    return list[k%2][n-1];
}
