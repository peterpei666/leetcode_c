#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int n;
    int* origin;
    int* current;
} Solution;

inline int randomInt(int r)
{
    return rand()%(r+1);
}

inline void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

Solution* solutionCreate(int* nums, int numsSize)
{
    Solution* obj=(Solution*)malloc(sizeof(Solution));
    obj->n=numsSize;
    obj->origin=(int*)malloc(sizeof(int)*numsSize);
    obj->current=(int*)malloc(sizeof(int)*numsSize);
    memcpy(obj->origin,nums,sizeof(int)*numsSize);
    memcpy(obj->current,nums,sizeof(int)*numsSize);
    srand((unsigned int)time(NULL));
    return obj;
}

int* solutionReset(Solution* obj, int* retSize)
{
    memcpy(obj->current,obj->origin,sizeof(int)*obj->n);
    *retSize=obj->n;
    return obj->current;
}

int* solutionShuffle(Solution* obj, int* retSize)
{
    int i;
    for(i=obj->n-1;i>0;i--)
    {
        swap(&obj->current[i],&obj->current[randomInt(i)]);
    }
    *retSize=obj->n;
    return obj->current;
}

void solutionFree(Solution* obj)
{
    free(obj->origin);
    free(obj->current);
    free(obj);
}
