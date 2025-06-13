#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned char visited[6250];

inline bool test(int a)
{
    return visited[a>>3]&(1<<(a&7))?true:false;
}

inline void set(int a)
{
    visited[a>>3]|=1<<(a&7);
}

inline void reset(int a)
{
    visited[a>>3]&=~(1<<(a&7));
}

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

bool canReach(int* arr, int n, int start)
{
    int i;
    int temp,l,r;
    queue* q=initialize();
    memset(visited,0,sizeof(visited));
    push(q,start);
    set(start);
    while(!empty(q))
    {
        temp=front(q);
        pop(q);
        l=temp-arr[temp];
        r=temp+arr[temp];
        if(l>=0&&l<n&&test(l)==false)
        {
            set(l);
            push(q,l);
        }
        if(r>=0&&r<n&&test(r)==false)
        {
            set(r);
            push(q,r);
        }
    }
    clear(q);
    for(i=0;i<n;i++)
    {
        if(arr[i]==0&&test(i))
        {
            return true;
        }
    }
    return false;
}
