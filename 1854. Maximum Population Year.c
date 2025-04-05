#include <stdio.h>
#include <stdlib.h>

int compare(const void* p1,const void* p2)
{
    int* a=(int*)p1;
    int* b=(int*)p2;
    return *a-*b;
}

int maximumPopulation(int** logs, int logsSize, int* logsColSize)
{
    int i,j=0,year=0,max=0;
    int* birth=(int*)malloc(sizeof(int)*logsSize);
    int* death=(int*)malloc(sizeof(int)*logsSize);
    for(i=0;i<logsSize;i++)
    {
        birth[i]=logs[i][0];
        death[i]=logs[i][1];
    }
    qsort(birth,logsSize,sizeof(int),compare);
    qsort(death,logsSize,sizeof(int),compare);
    for(i=0;i<logsSize;i++)
    {
        while(j<logsSize&&death[j]<=birth[i])
        {
            j++;
        }
        if(i+1-j>max)
        {
            max=i+1-j;
            year=birth[i];
        }
    }
    free(birth);
    free(death);
    return year;
}

