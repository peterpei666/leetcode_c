#include <stdio.h>
#include <stdlib.h>

int numSquares(int n)
{
    int i,j,temp;
    int* list=(int*)malloc(sizeof(int)*(n+1));
    for(i=0;i<n+1;i++)
    {
        list[i]=i;
    }
    for(i=2;i*i<=n;i++)
    {
        for(j=i*i;j<=n;j++)
        {
            list[j]=(list[j]>(list[j-i*i]+1))?list[j-i*i]+1:list[j];
        }
    }
    temp=list[n];
    free(list);
    return temp;
}

