#include <stdio.h>
#include <stdlib.h>

int* constructArray(int n, int k, int* returnSize)
{
    int i,j,count=0;
    i=1;
    j=n;
    *returnSize=n;
    int* list=(int*)malloc(sizeof(int)*n);
    while(i<=j)
    {
        if(k>1)
        {
            if(k%2)
            {
                list[count]=i;
                i++;
            }
            else
            {
                list[count]=j;
                j--;
            }
            k--;
        }
        else
        {
            list[count]=i;
            i++;
        }
        count++;
    }
    return list;
}

