#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char c;
    int n;
} pair;

typedef struct
{
    pair* list;
    int sz;
    int capacity;
} stack;

stack* initialize(void)
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->list=(pair*)malloc(sizeof(pair)*100);
    s->sz=0;
    s->capacity=100;
    return s;
}

void push(stack* s,char c)
{
    if(s->sz/100*100+100!=s->capacity)
    {
        s->capacity=s->sz/100*100+100;
        s->list=(pair*)realloc(s->list,s->capacity*sizeof(pair));
    }
    s->list[s->sz]=(pair){c,1};
    s->sz++;
}

pair* top(stack* s)
{
    if(s->sz==0)
    {
        return NULL;
    }
    else
    {
        return &s->list[s->sz-1];
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
            s->list=(pair*)realloc(s->list,s->capacity*sizeof(pair));
        }
    }
}

void clear(stack* s)
{
    free(s->list);
    free(s);
}

void reverse(char* s)
{
    int i,l;
    char temp;
    l=(int)strlen(s);
    for(i=0;i<l/2;i++)
    {
        temp=s[i];
        s[i]=s[l-i-1];
        s[l-i-1]=temp;
    }
}

char* removeDuplicates(char* s)
{
    int i,m=0;
    pair* temp;
    int len=(int)strlen(s);
    stack* list=initialize();
    char* ret=(char*)malloc(sizeof(char)*(len+1));
    for(i=0;i<len;i++)
    {
        temp=top(list);
        if(temp==NULL||temp->c!=s[i])
        {
            push(list,s[i]);
        }
        else
        {
            temp->n++;
            if(temp->n==2)
            {
                pop(list);
            }
        }
    }
    while(list->sz)
    {
        temp=top(list);
        while(temp->n)
        {
            temp->n--;
            ret[m]=temp->c;
            m++;
        }
        pop(list);
    }
    ret[m]='\0';
    reverse(ret);
    clear(list);
    return ret;
}
