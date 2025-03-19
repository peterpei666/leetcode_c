#include <stdio.h>
#include <stdlib.h>

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

int coinChange(int* coins,int coinsSize,int amount)
{
    int i,j,temp;
    int* list=(int*)malloc((amount+1)*sizeof(int));
    for(i=0;i<=amount;i++)
    {
        list[i]=-1;
    }
    qsort(coins,coinsSize,sizeof(int),compare);
    list[0]=0;
    for(i=0;i<coinsSize&&coins[i]<=amount;i++)
    {
        for(j=coins[i];j<=amount;j++)
        {
            if(list[j]==-1&&list[j-coins[i]]!=-1)
            {
                list[j]=list[j-coins[i]]+1;
            }
            else if(list[j]!=-1&&list[j-coins[i]]!=-1)
            {
                list[j]=(list[j]>list[j-coins[i]]+1)?list[j-coins[i]]+1:list[j];
            }
        }
    }
    temp=list[amount];
    free(list);
    return temp;
}

