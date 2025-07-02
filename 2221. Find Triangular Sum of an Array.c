#include <stdio.h>
#include <stdlib.h>

int triangularSum(int* nums, int n)
{
    int i,j;
    unsigned char memo[2][n];
    for(i=0;i<n;i++)
    {
        memo[0][i]=nums[i]%10;
    }
    for(i=1;n-i>=1;i++)
    {
        for(j=0;j<n-i;j++)
        {
            memo[i%2][j]=(memo[(i-1)%2][j]+memo[(i-1)%2][j+1])%10;
        }
    }
    return memo[(n-1)%2][0];
}
