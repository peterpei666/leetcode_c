#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize)
{
    int r=matrixSize;
    int c=matrixColSize[0];
    int ans=0;
    int height[c+1];
    memset(height,0,sizeof(height));
    stack* stk=initialize();
    push(stk,-1);
    for(int k=0;k<r;k++)
    {
        for(int i=0;i<c;i++)
        {
            if(matrix[k][i]=='1')
            {
                height[i]++;
            }
            else
            {
                height[i]=0;
            }
        }
        for(int i=0;i<=c;i++)
        {
            while(top(stk)!=-1&&height[i]<=height[top(stk)])
            {
                int h=height[top(stk)];
                pop(stk);
                int w=i-top(stk)-1;
                ans=max(ans,w*h);
            }
            push(stk,i);
        }
        stk->sz=1;
    }
    clear(stk);
    return ans;
}
