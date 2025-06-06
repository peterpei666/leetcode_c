#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* list;
    int sz;
    int capacity;
} stack;

inline stack* initialize(void)
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

inline char top(stack* s)
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

inline void clear(stack* s)
{
    free(s->list);
    free(s);
}

char* robotWithString(char* s)
{
    int i,j,minc=0;
    int cnt[26]={0};
    int len=(int)strlen(s);
    stack* t=initialize();
    for(i=0;i<len;i++)
    {
        cnt[s[i]-'a']++;
    }
    char* ret=(char*)malloc(sizeof(char)*(len+1));
    for(i=0,j=0;i<len;i++)
    {
        push(t,s[i]);
        cnt[s[i]-'a']--;
        while(minc+'a'<'z'&&cnt[minc]==0)
        {
            minc++;
        }
        while(t->sz&&top(t)<=minc+'a')
        {
            ret[j]=top(t);
            j++;
            pop(t);
        }
    }
    ret[len]='\0';
    clear(t);
    return ret;
}
