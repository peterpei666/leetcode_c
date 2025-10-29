#include <stdio.h>
#include <stdlib.h>

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

typedef struct
{
    int a;
    int b;
} pair;

typedef struct
{
    pair* list;
    int sz;
    int capacity;
} stack;

static inline stack* initialize(void)
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->list=(pair*)malloc(sizeof(pair)*100);
    s->sz=0;
    s->capacity=100;
    return s;
}

static inline void push(stack* s,pair n)
{
    if(s->sz/100*100+100!=s->capacity)
    {
        s->capacity=s->sz/100*100+100;
        s->list=(pair*)realloc(s->list,s->capacity*sizeof(pair));
    }
    s->list[s->sz]=n;
    s->sz++;
}

static inline pair top(stack* s)
{
    if(s->sz==0)
    {
        return (pair){0, 0};
    }
    else
    {
        return s->list[s->sz-1];
    }
}

static inline void pop(stack* s)
{
    if(s->sz)
    {
        s->sz--;
        if(s->sz/100*100+100!=s->capacity)
        {
            s->capacity=s->sz/100*100+100;
            s->list=(pair*)realloc(s->list,s->capacity*sizeof(pair));
        }
    }
}

static inline void clear(stack* s)
{
    free(s->list);
    free(s);
}

typedef struct
{
    stack* stk;
} MinStack;


MinStack* minStackCreate(void)
{
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->stk = initialize();
    return obj;
}

void minStackPush(MinStack* obj, int val)
{
    if (obj->stk->sz == 0)
    {
        push(obj->stk, (pair){val, val});
    }
    else
    {
        push(obj->stk, (pair){val, min(val, top(obj->stk).b)});
    }
}

void minStackPop(MinStack* obj)
{
    pop(obj->stk);
}

int minStackTop(MinStack* obj)
{
    return top(obj->stk).a;
}

int minStackGetMin(MinStack* obj)
{
    return top(obj->stk).b;
}

void minStackFree(MinStack* obj)
{
    free(obj->stk);
    free(obj);
}
