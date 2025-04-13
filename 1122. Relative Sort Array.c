#include <stdio.h>
#include <stdlib.h>

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
    int m,i;
    int count[1001]={0};
    for(i=0;i<arr1Size;i++)
    {
        count[arr1[i]]++;
    }
    for(i=0,m=0;i<arr2Size;i++)
    {
        while(count[arr2[i]])
        {
            arr1[m]=arr2[i];
            count[arr2[i]]--;
            m++;
        }
    }
    for(i=0;i<=1000;i++)
    {
        while(count[i])
        {
            arr1[m]=i;
            count[i]--;
            m++;
        }
    }
    *returnSize=arr1Size;
    return arr1;
}
