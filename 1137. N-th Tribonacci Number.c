#include <stdio.h>
#include <stdlib.h>

int tribonacci(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1||n==2)
    {
        return 1;
    }
    int i,temp=0;
    int* arr=(int*)malloc(3*sizeof(int));
    arr[0]=1;
    arr[1]=1;
    arr[2]=0;
    for(i=2;i<n;i++)
    {
        temp=arr[0]+arr[1]+arr[2];
        arr[2]=arr[1];
        arr[1]=arr[0];
        arr[0]=temp;
    }
    free(arr);
    return temp;
}
