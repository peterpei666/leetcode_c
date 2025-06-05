#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp1(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

int cmp2(const void* p1,const void* p2)
{
    return memcmp(*(int**)p1,*(int**)p2,sizeof(int)*3);
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

int maxHeight(int** cuboids, int n, int* cuboidsColSize)
{
    int i,j;
    int ret=0;
    int dp[n];
    for(i=0;i<n;i++)
    {
        qsort(cuboids[i],3,sizeof(int),cmp1);
    }
    qsort(cuboids,n,sizeof(int*),cmp2);
    for(i=0;i<n;i++)
    {
        dp[i]=cuboids[i][2];
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(cuboids[i][0]>=cuboids[j][0]&&cuboids[i][1]>=cuboids[j][1]&&cuboids[i][2]>=cuboids[j][2])
            {
                dp[i]=max(dp[i],dp[j]+cuboids[i][2]);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        ret=max(ret,dp[i]);
    }
    return ret;
}
