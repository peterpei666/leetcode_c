#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct
{
    int effort;
    int earn;
} job;

int compare(const void* p1,const void* p2)
{
    job* a=(job*)p1;
    job* b=(job*)p2;
    return a->effort-b->effort;
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize)
{
    int i,j,max;
    job* list=(job*)malloc(difficultySize*sizeof(job));
    for(i=0;i<difficultySize;i++)
    {
        list[i].effort=difficulty[i];
        list[i].earn=profit[i];
    }
    qsort(list,difficultySize,sizeof(job),compare);
    int* option=(int*)malloc(sizeof(int)*100001);
    option[0]=0;
    j=0;
    for(i=1;i<100001;i++)
    {
        if(j>=difficultySize||list[j].effort>i)
        {
            option[i]=option[i-1];
        }
        else
        {
            max=option[i-1];
            while(j<difficultySize&&list[j].effort==i)
            {
                if(list[j].earn>max)
                {
                    max=list[j].earn;
                }
                j++;
            }
            option[i]=max;
        }
    }
    max=0;
    for(i=0;i<workerSize;i++)
    {
        max+=option[worker[i]];
    }
    free(list);
    free(option);
    return max;
}
