#include <stdio.h>
#include <stdlib.h>

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

int change(int amount, int* coins, int coinsSize)
{
    int i,j,temp;
    int* list=(int*)calloc(amount+1,sizeof(int));
    qsort(coins,coinsSize,sizeof(int),compare);
    list[0]=1;
    for(i=0;i<coinsSize&&coins[i]<=amount;i++)
    {
        for(j=coins[i];j<=amount;j++)
        {
            list[j]=list[j]+list[j-coins[i]];
        }
    }
    temp=list[amount];
    free(list);
    return temp;
}
