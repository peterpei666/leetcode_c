#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int* list;
    int sz;
    int capacity;
} stack;

static inline stack* initialize(void)
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->list=(int*)malloc(sizeof(int)*100);
    s->sz=0;
    s->capacity=100;
    return s;
}

static inline void push(stack* s,int n)
{
    if(s->sz/100*100+100!=s->capacity)
    {
        s->capacity=s->sz/100*100+100;
        s->list=(int*)realloc(s->list,s->capacity*sizeof(int));
    }
    s->list[s->sz]=n;
    s->sz++;
}

static inline bool empty(stack* s)
{
    return s->sz == 0;
}

static inline int top(stack* s)
{
    if(s->sz==0)
    {
        return -1;
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
            s->list=(int*)realloc(s->list,s->capacity*sizeof(int));
        }
    }
}

static inline void clear(stack* s)
{
    free(s->list);
    free(s);
}

int minNumberOperations(int* target, int n)
{
    int ans = 0;
    stack* stk = initialize();
    for (int i = 0; i < n; i++)
    {
        if (!empty(stk) && top(stk) >= target[i])
        {
            ans += top(stk) - target[i];
        }
        while (!empty(stk) && top(stk) >= target[i])
        {
            pop(stk);
        }
        push(stk, target[i]);
    }
    ans += top(stk);
    clear(stk);
    return ans;
}
