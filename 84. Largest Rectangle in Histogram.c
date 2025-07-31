#include <stdio.h>
#include <stdlib.h>

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

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int largestRectangleArea(int* heights, int n)
{
    stack* stk=initialize();
    push(stk,-1);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        while(top(stk)!=-1&&heights[top(stk)]>=heights[i])
        {
            int h=heights[top(stk)];
            pop(stk);
            int w=i-top(stk)-1;
            ans=max(ans,h*w);
        }
        push(stk,i);
    }
    while (top(stk)!=-1)
    {
        int h=heights[top(stk)];
        pop(stk);
        int w=n-top(stk)-1;
        ans=max(ans,h*w);
    }
    clear(stk);
    return ans;
}
