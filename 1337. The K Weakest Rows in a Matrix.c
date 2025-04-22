#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int p;
    int id;
} pair;

int cmp(const void* p1,const void* p2)
{
    pair* a=(pair*)p1;
    pair* b=(pair*)p2;
    if(a->p!=b->p)
    {
        return a->p-b->p;
    }
    return a->id-b->id;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize)
{
    int i,j;
    pair* list=(pair*)malloc(sizeof(pair)*matSize);
    for(i=0;i<matSize;i++)
    {
        j=0;
        while(j<matColSize[i]&&mat[i][j])
        {
            j++;
        }
        list[i]=(pair){j,i};
    }
    qsort(list,matSize,sizeof(pair),cmp);
    *returnSize=k;
    int* ret=(int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++)
    {
        ret[i]=list[i].id;
    }
    free(list);
    return ret;
}
