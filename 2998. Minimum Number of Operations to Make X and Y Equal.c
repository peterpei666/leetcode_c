#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct queue
{
    int* list;
    int head;
    int sz;
    int capacity;
} queue;

queue* initialize(void)
{
    queue* q=(queue*)malloc(sizeof(queue));
    q->list=(int*)malloc(sizeof(int)*100);
    q->head=0;
    q->sz=0;
    q->capacity=100;
    return q;
}

queue* reallocation(queue* q)
{
    int size=q->sz-q->head;
    q->capacity*=2;
    int* new=(int*)malloc(sizeof(int)*q->capacity);
    memcpy(new,q->list+q->head,sizeof(int)*size);
    free(q->list);
    q->sz-=q->head;
    q->head=0;
    q->list=new;
    return q;
}

inline void push(queue* q,int a)
{
    if(q->sz>=q->capacity)
    {
        reallocation(q);
    }
    q->list[q->sz]=a;
    q->sz++;
}

inline int front(queue* q)
{
    return q->list[q->head];
}

inline void pop(queue* q)
{
    q->head++;
}
 
inline bool empty(queue* q)
{
    return q->head==q->sz;
}

inline void clear(queue* q)
{
    free(q->list);
    free(q);
}

int minimumOperationsToMakeEqual(int x, int y)
{
    int t;
    int memo[10001];
    queue* q=initialize();
    memset(memo,-1,sizeof(memo));
    memo[x]=0;
    push(q,x);
    while(!empty(q))
    {
        t=front(q);
        pop(q);
        if(t==y)
        {
            return memo[y];
        }
        if(t-1>0&&(memo[t-1]==-1||memo[t-1]>memo[t]+1))
        {
            memo[t-1]=memo[t]+1;
            push(q,t-1);
        }
        if(t+1<=10000&&(memo[t+1]==-1||memo[t+1]>memo[t]+1))
        {
            memo[t+1]=memo[t]+1;
            push(q,t+1);
        }
        if(t%5==0&&(memo[t/5]==-1||memo[t/5]>memo[t]+1))
        {
            memo[t/5]=memo[t]+1;
            push(q,t/5);
        }
        if(t%11==0&&(memo[t/11]==-1||memo[t/11]>memo[t]+1))
        {
            memo[t/11]=memo[t]+1;
            push(q,t/11);
        }
    }
    return memo[y];
}
