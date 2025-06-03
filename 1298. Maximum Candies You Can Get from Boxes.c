#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool test(int a,unsigned char visited[])
{
    return visited[a>>3]&(1<<(a&7))?true:false;
}

void set(int a,unsigned char visited[])
{
    visited[a>>3]|=1<<(a&7);
}

void reset(int a,unsigned char visited[])
{
    visited[a>>3]&=~(1<<(a&7));
}

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

int maxCandies(int* status, int statusSize, int* candies, int candiesSize, int** keys, int keysSize, int* keysColSize, int** containedBoxes, int containedBoxesSize, int* containedBoxesColSize, int* initialBoxes, int initialBoxesSize)
{
    int i,j,ans=0,box;
    int n=statusSize;
    unsigned char open[125];
    unsigned char used[125];
    unsigned char have[125];
    memset(open,0,sizeof(open));
    memset(used,0,sizeof(used));
    memset(have,0,sizeof(have));
    stack* list=initialize();
    for(i=0;i<n;i++)
    {
        if(status[i])
        {
            set(i,open);
        }
    }
    for(i=0;i<initialBoxesSize;i++)
    {
        set(initialBoxes[i],have);
        if(test(initialBoxes[i],open))
        {
            push(list,initialBoxes[i]);
            set(initialBoxes[i],used);
            ans+=candies[initialBoxes[i]];
        }
    }
    while(list->sz)
    {
        box=top(list);
        pop(list);
        for(j=0;j<keysColSize[box];j++)
        {
            set(keys[box][j],open);
            if(!test(keys[box][j],used)&&test(keys[box][j],have))
            {
                push(list,keys[box][j]);
                set(keys[box][j],used);
                ans+=candies[keys[box][j]];
            }
        }
        for(j=0;j<containedBoxesColSize[box];j++)
        {
            set(containedBoxes[box][j],have);
            if(!test(containedBoxes[box][j],used)&&test(containedBoxes[box][j],open))
            {
                push(list,containedBoxes[box][j]);
                set(containedBoxes[box][j],used);
                ans+=candies[containedBoxes[box][j]];
            }
        }
    }
    clear(list);
    return ans;
}
