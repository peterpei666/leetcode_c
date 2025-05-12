#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned char visited[130000];

bool test(int a,int b)
{
    int temp=a*1001+b;
    return visited[temp>>3]&(1<<(temp&7))?true:false;
}

void set(int a,int b)
{
    int temp=a*1001+b;
    visited[temp>>3]|=1<<(temp&7);
}

typedef struct pair
{
    int a;
    int b;
} pair;

typedef struct queue
{
    pair* list;
    int head;
    int sz;
    int capacity;
} queue;

queue* initialize(void)
{
    queue* q=(queue*)malloc(sizeof(queue));
    q->list=(pair*)malloc(sizeof(pair)*100);
    q->head=0;
    q->sz=0;
    q->capacity=100;
    return q;
}

queue* reallocation(queue* q)
{
    q->capacity*=2;
    pair* new=(pair*)malloc(sizeof(pair)*q->capacity);
    memcpy(new,q->list+q->head,sizeof(pair)*(q->sz-q->head));
    q->sz-=q->head;
    q->head=0;
    free(q->list);
    q->list=new;
    return q;
}

void push(queue* q,int a,int b)
{
    if(q->sz>=q->capacity)
    {
        reallocation(q);
    }
    q->list[q->sz]=(pair){a,b};
    q->sz++;
}

pair top(queue* q)
{
    return q->list[q->head];
}

void pop(queue* q)
{
    q->head++;
}

inline int mini(int a,int b)
{
    return a<b?a:b;
}

bool canMeasureWater(int x, int y, int target)
{
    if(x+y<target)
    {
        return false;
    }
    int w;
    pair temp;
    memset(visited,0,sizeof(visited));
    queue* q=initialize();
    push(q,x,y);
    set(x,y);
    push(q,x,0);
    set(x,0);
    push(q,0,y);
    set(0,y);
    push(q,0,0);
    set(0,0);
    while(q->head<q->sz)
    {
        temp=top(q);
        pop(q);
        if(temp.a+temp.b==target)
        {
            free(q->list);
            free(q);
            return true;
        }
        w=mini(temp.a,y-temp.b);
        if(!test(temp.a-w,temp.b+w))
        {
            push(q,temp.a-w,temp.b+w);
            set(temp.a-w,temp.b+w);
        }
        w=mini(x-temp.a,temp.b);
        if(!test(temp.a+w,temp.b-w))
        {
            push(q,temp.a+w,temp.b-w);
            set(temp.a+w,temp.b-w);
        }
        if(!test(x,temp.b))
        {
            push(q,x,temp.b);
            set(x,temp.b);
        }
        if(!test(temp.a,y))
        {
            push(q,temp.a,y);
            set(temp.a,y);
        }
        if(!test(temp.a,0))
        {
            push(q,temp.a,0);
            set(temp.a,0);
        }
        if(!test(0,temp.b))
        {
            push(q,0,temp.b);
            set(0,temp.b);
        }
    }
    free(q->list);
    free(q);
    return false;
}
