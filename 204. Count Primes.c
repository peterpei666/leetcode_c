#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int countPrimes(int n)
{
    if(n==0||n==1)
    {
        return 0;
    }
    int i,j,count=0;
    bool* list=(bool*)malloc((n+1)*sizeof(bool));
    memset(list,true,n+1);
    list[0]=false;
    list[1]=false;
    for(i=2;i<=(int)sqrt(n);i++)
    {
        if(list[i])
        {
            for(j=i;i*j<=n;j++)
            {
                list[i*j]=false;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(list[i])
        {
            count++;
        }
    }
    free(list);
    return count;
}
