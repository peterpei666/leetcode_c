#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int sz;
    int stk[100];
} MyStack;

MyStack* myStackCreate(void)
{
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->sz = 0;
    return obj;
}

void myStackPush(MyStack* obj, int x)
{
    obj->stk[obj->sz] = x;
    obj->sz++;
}

int myStackPop(MyStack* obj)
{
    obj->sz--;
    return obj->stk[obj->sz];
}

int myStackTop(MyStack* obj)
{
    return obj->stk[obj->sz - 1];
}

bool myStackEmpty(MyStack* obj)
{
    return obj->sz == 0;
}

void myStackFree(MyStack* obj)
{
    free(obj);
}
