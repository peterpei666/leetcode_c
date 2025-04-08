#include <stdio.h>
#include <stdlib.h>

int getMaximumGenerated(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    int i,max=1;
    int* list=(int*)malloc(sizeof(int)*(n+1));
    list[0]=0;
    list[1]=1;
    for(i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            list[i]=list[i/2];
        }
        else
        {
            list[i]=list[i/2]+list[i/2+1];
        }
        if(list[i]>max)
        {
            max=list[i];
        }
    }
    free(list);
    return max;
}

