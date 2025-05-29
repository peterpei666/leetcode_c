#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int maxsize;
    int sz;
    int* stack;
} CustomStack;


CustomStack* customStackCreate(int maxSize)
{
    CustomStack* obj=(CustomStack*)malloc(sizeof(CustomStack));
    obj->sz=0;
    obj->maxsize=maxSize;
    obj->stack=(int*)malloc(sizeof(int)*maxSize);
    return obj;
}

void customStackPush(CustomStack* obj, int x)
{
    if(obj->sz<obj->maxsize)
    {
        obj->stack[obj->sz]=x;
        obj->sz++;
    }
}

int customStackPop(CustomStack* obj)
{
    if(obj->sz)
    {
        obj->sz--;
        return obj->stack[obj->sz];
    }
    return -1;
}

void customStackIncrement(CustomStack* obj, int k, int val)
{
    int i;
    for(i=0;i<k&&i<obj->sz;i++)
    {
        obj->stack[i]+=val;
    }
}

void customStackFree(CustomStack* obj)
{
    free(obj->stack);
    free(obj);
}
