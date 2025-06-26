#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

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
    int size=q->sz-q->head;
    q->capacity*=2;
    pair* new=(pair*)malloc(sizeof(pair)*q->capacity);
    memcpy(new,q->list+q->head,sizeof(pair)*size);
    free(q->list);
    q->sz-=q->head;
    q->head=0;
    q->list=new;
    return q;
}

inline void push(queue* q,int a,int b)
{
    if(q->sz>=q->capacity)
    {
        reallocation(q);
    }
    q->list[q->sz]=(pair){a,b};
    q->sz++;
}

inline pair front(queue* q)
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

inline int min(int a,int b)
{
    return a<b?a:b;
}

int minimumTotal(int** triangle, int n, int* triangleColSize)
{
    int memo[200][200];
    pair temp;
    int i,r,c;
    int ans=INT_MAX;
    queue* q=initialize();
    memset(memo,0x7f,sizeof(memo));
    memo[0][0]=triangle[0][0];
    push(q,0,0);
    while(!empty(q))
    {
        temp=front(q);
        r=temp.a;
        c=temp.b;
        pop(q);
        if(r+1==n)
        {
            continue;
        }
        if(memo[r+1][c]>memo[r][c]+triangle[r+1][c])
        {
            memo[r+1][c]=memo[r][c]+triangle[r+1][c];
            push(q,r+1,c);
        }
        if(memo[r+1][c+1]>memo[r][c]+triangle[r+1][c+1])
        {
            memo[r+1][c+1]=memo[r][c]+triangle[r+1][c+1];
            push(q,r+1,c+1);
        }
    }
    for(i=0;i<n;i++)
    {
        ans=min(ans,memo[n-1][i]);
    }
    return ans;
}
