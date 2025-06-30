#include <stdio.h>
#include <stdlib.h>

int maxChunksToSorted(int* arr, int n)
{
    int stk[10];
    int i,k=0;
    for(i=0;i<n;i++)
    {
        if(k&&stk[k-1]>arr[i])
        {
            int temp=stk[k-1];
            while(k&&stk[k-1]>arr[i])
            {
                k--;
            }
            stk[k]=temp;
            k++;
        }
        else
        {
            stk[k]=arr[i];
            k++;
        }
    }
    return k;
}
