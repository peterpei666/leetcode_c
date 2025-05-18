#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct pair
{
    long long a;
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

void push(queue* q,long long a,int b)
{
    if(q->sz>=q->capacity)
    {
        reallocation(q);
    }
    q->list[q->sz]=(pair){a,b};
    q->sz++;
}

pair front(queue* q)
{
    return q->list[q->head];
}

pair back(queue* q)
{
    return q->list[q->sz-1];
}

void pop_front(queue* q)
{
    q->head++;
}

void pop_back(queue* q)
{
    q->sz--;
}

inline int mini(int a,int b)
{
    return a<b?a:b;
}

int shortestSubarray(int* nums, int n, int k)
{
    int i;
    int ret=INT_MAX;
    long long cur=0;
    queue* q=initialize();
    for(i=0;i<n;i++)
    {
        cur+=nums[i];
        if(cur>=k)
        {
            ret=mini(ret,i+1);
        }
        while(q->sz>q->head&&cur-front(q).a>=k)
        {
            ret=mini(ret,i-front(q).b);
            pop_front(q);
        }
        while(q->sz>q->head&&back(q).a>cur)
        {
            pop_back(q);
        }
        push(q,cur,i);
    }
    free(q->list);
    free(q);
    return ret==INT_MAX?-1:ret;
}
