#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int* list;
    int sz;
    int capacity;
} stack;

stack* initialize(void)
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->list=(int*)malloc(sizeof(int)*100);
    s->sz=0;
    s->capacity=100;
    return s;
}

void push(stack* s,int n)
{
    if(s->sz/100*100+100!=s->capacity)
    {
        s->capacity=s->sz/100*100+100;
        s->list=(int*)realloc(s->list,s->capacity*sizeof(int));
    }
    s->list[s->sz]=n;
    s->sz++;
}

int top(stack* s)
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
            s->list=(int*)realloc(s->list,s->capacity*sizeof(int));
        }
    }
}

void clear(stack* s)
{
    free(s->list);
    free(s);
}

char* clearStars(char* s)
{
    int i,j;
    int n=(int)strlen(s);
    stack* list[26];
    for(i=0;i<26;i++)
    {
        list[i]=initialize();
    }
    for(i=0;i<n;i++)
    {
        if(s[i]!='*')
        {
            push(list[s[i]-'a'],i);
        }
        else
        {
            for(j=0;j<26;j++)
            {
                if(list[j]->sz)
                {
                    s[top(list[j])]='*';
                    pop(list[j]);
                    break;
                }
            }
        }
    }
    for(i=0;i<26;i++)
    {
        clear(list[i]);
    }
    char* ret=(char*)malloc(sizeof(char)*(n+1));
    for(i=0,j=0;i<n;i++)
    {
        if(s[i]!='*')
        {
            ret[j]=s[i];
            j++;
        }
    }
    ret[j]='\0';
    return ret;
}
