#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

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

static inline void push(stack* s,int a,int b)
{
    if(s->sz/100*100+100!=s->capacity)
    {
        s->capacity=s->sz/100*100+100;
        s->list=(pair*)realloc(s->list,s->capacity*sizeof(pair));
    }
    s->list[s->sz]=(pair){a,b};
    s->sz++;
}

static inline pair top(stack* s)
{
    if(s->sz==0)
    {
        return (pair){-1,-1};
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

int calculate(char* s)
{
    int sum=0;
    int sign=1;
    int n=(int)strlen(s);
    stack* stk=initialize();
    for(int i=0;i<n;i++)
    {
        if(isdigit(s[i]))
        {
            long long num=0;
            while(i<n&&isdigit(s[i]))
            {
                num=num*10+(s[i]-'0');
                i++;
            }
            i--;
            sum+=num*sign;
            sign=1;
        }
        else if(s[i]=='(')
        {
            push(stk,sum,sign);
            sum=0;
            sign=1;
        }
        else if(s[i]==')')
        {
            sum=top(stk).a+top(stk).b*sum;
            pop(stk);
        }
        else if(s[i]=='-')
        {
            sign=-sign;
        }
    }
    clear(stk);
    return sum;
}
