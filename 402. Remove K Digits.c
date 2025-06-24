#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int* list;
    int sz;
    int capacity;
} stack;

inline stack* initialize(void)
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->list=(int*)malloc(sizeof(int)*100);
    s->sz=0;
    s->capacity=100;
    return s;
}

inline void push(stack* s,int n)
{
    if(s->sz/100*100+100!=s->capacity)
    {
        s->capacity=s->sz/100*100+100;
        s->list=(int*)realloc(s->list,s->capacity*sizeof(int));
    }
    s->list[s->sz]=n;
    s->sz++;
}

inline int top(stack* s)
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

inline void pop(stack* s)
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

inline void clear(stack* s)
{
    free(s->list);
    free(s);
}

char* removeKdigits(char* num, int k)
{
    int i,j;
    int n=(int)strlen(num);
    char* ret=(char*)malloc(n-k+2);
    stack* stk=initialize();
    for(i=0;i<n;i++)
    {
        while(k&&stk->sz&&num[top(stk)]>num[i])
        {
            k--;
            num[top(stk)]='*';
            pop(stk);
        }
        push(stk,i);
    }
    clear(stk);
    i=n-1;
    while(k)
    {
        if(num[i]!='*')
        {
            num[i]='*';
            k--;
        }
        i--;
    }
    for(i=0,j=0;i<n;i++)
    {
        if(num[i]=='*')
        {
            continue;
        }
        if(num[i]=='0'&&j==0)
        {
            continue;
        }
        ret[j]=num[i];
        j++;
    }
    if(j==0)
    {
        ret[0]='0';
        ret[1]='\0';
        return ret;
    }
    ret[j]='\0';
    return ret;
}
