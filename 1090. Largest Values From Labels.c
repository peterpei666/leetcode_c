#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int val;
    int id;
} pair;

int cmp(const void* p1,const void* p2)
{
    pair* a=(pair*)p1;
    pair* b=(pair*)p2;
    return b->val-a->val;
}

int largestValsFromLabels(int* values, int valuesSize, int* labels, int labelsSize, int numWanted, int useLimit)
{
    int i,sum=0;
    int count[20001]={0};
    pair* list=(pair*)malloc(sizeof(pair)*valuesSize);
    for(i=0;i<valuesSize;i++)
    {
        list[i]=(pair){values[i],labels[i]};
    }
    qsort(list,valuesSize,sizeof(pair),cmp);
    for(i=0;i<valuesSize&&numWanted;i++)
    {
        if(count[list[i].id]<useLimit)
        {
            count[list[i].id]++;
            sum+=list[i].val;
            numWanted--;
        }
    }
    free(list);
    return sum;
}
