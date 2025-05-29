#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

bool isValid(char* s)
{
    int i,l;
    stack* list=initialize();
    l=(int)strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i]!='c')
        {
            push(list,s[i]);
        }
        else
        {
            if(list->sz<2)
            {
                return false;
            }
            if(list->list[list->sz-1]=='b'&&list->list[list->sz-2]=='a')
            {
                pop(list);
                pop(list);
            }
            else
            {
                push(list,s[i]);
            }
        }
    }
    if(list->sz)
    {
        clear(list);
        return false;
    }
    clear(list);
    return true;
}
