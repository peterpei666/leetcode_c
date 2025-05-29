#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* list;
    int sz;
    int capacity;
} stack;

stack* initialize(void)
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->list=(char*)malloc(sizeof(char)*100);
    s->sz=0;
    s->capacity=100;
    return s;
}

void push(stack* s,char n)
{
    if(s->sz/100*100+100!=s->capacity)
    {
        s->capacity=s->sz/100*100+100;
        s->list=(char*)realloc(s->list,s->capacity*sizeof(char));
    }
    s->list[s->sz]=n;
    s->sz++;
}

char top(stack* s)
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

void pop(stack* s)
{
    if(s->sz)
    {
        s->sz--;
        if(s->sz/100*100+100!=s->capacity)
        {
            s->capacity=s->sz/100*100+100;
            s->list=(char*)realloc(s->list,s->capacity*sizeof(char));
        }
    }
}

void clear(stack* s)
{
    free(s->list);
    free(s);
}

char* removeStars(char* s)
{
    int i,len;
    stack* list=initialize();
    len=(int)strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]!='*')
        {
            push(list,s[i]);
        }
        else
        {
            pop(list);
        }
    }
    push(list,'\0');
    char* ret=strdup(list->list);
    clear(list);
    return ret;
}
