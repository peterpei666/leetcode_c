#include <stdio.h>
#include <stdlib.h>

int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize)
{
    int i,j,count=0;
    int* arr=(int*)calloc(basketsSize,sizeof(int));
    for(i=0;i<fruitsSize;i++)
    {
        for(j=0;j<basketsSize;j++)
        {
            if(arr[j]==0&&fruits[i]<=baskets[j])
            {
                arr[j]=1;
                count++;
                break;
            }
        }
    }
    return fruitsSize-count;
}
