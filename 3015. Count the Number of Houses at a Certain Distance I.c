#include <stdio.h>
#include <stdlib.h>

inline int min(int a,int b)
{
    return a<b?a:b;
}

int* countOfPairs(int n, int x, int y, int* returnSize)
{
    int i,j,temp;
    int* ret=(int*)calloc(n,sizeof(int));
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            temp=j-i;
            temp=min(temp,abs(x-i)+abs(y-j)+1);
            temp=min(temp,abs(x-j)+abs(y-i)+1);
            ret[temp-1]++;
        }
    }
    for(i=0;i<n;i++)
    {
        ret[i]*=2;
    }
    *returnSize=n;
    return ret;
}
