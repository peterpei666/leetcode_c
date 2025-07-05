#include <stdio.h>
#include <stdlib.h>

int findLucky(int* arr, int n)
{
    int i;
    int freq[501]={0};
    for(i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    for(i=500;i>=1;i--)
    {
        if(freq[i]==i)
        {
            return i;
        }
    }
    return -1;
}
