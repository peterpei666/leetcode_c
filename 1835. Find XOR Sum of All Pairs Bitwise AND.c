#include <stdio.h>
#include <stdlib.h>

int getXORSum(int* arr1, int n1, int* arr2, int n2)
{
    int i,m=0,n=0;
    for(i=0;i<n1;i++)
    {
        m^=arr1[i];
    }
    for(i=0;i<n2;i++)
    {
        n^=arr2[i];
    }
    return m&n;
}
