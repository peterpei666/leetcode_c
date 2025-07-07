#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static inline int max(int a,int b)
{
    return a>b?a:b;
}

struct heap
{
    int* list;
    int size;
    int capacity;
};

static inline struct heap* initialize(int n)
{
    struct heap* h=(struct heap*)malloc(sizeof(struct heap));
    h->size=0;
    h->capacity=n;
    h->list=(int*)malloc(sizeof(int)*n);
    return h;
}

static inline void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void heapify(struct heap* minheap,int i)
{
    int smallest=i;
    int l,r;
    while(1)
    {
        l=2*i+1;
        r=2*i+2;
        if(l<minheap->size&&minheap->list[l]<minheap->list[smallest])
        {
            smallest=l;
        }
        if(r<minheap->size&&minheap->list[r]<minheap->list[smallest])
        {
            smallest=r;
        }
        if(i==smallest)
        {
            break;
        }
        swap(&minheap->list[i],&minheap->list[smallest]);
        i=smallest;
    }
}

static inline bool empty(struct heap* h)
{
    return h->size==0;
}

void push(struct heap* minheap,int n)
{
    if(minheap->size>=minheap->capacity)
    {
        minheap->capacity*=2;
        minheap->list=(int*)realloc(minheap->list,sizeof(int)*minheap->capacity);
    }
    int i=minheap->size;
    minheap->size++;
    minheap->list[i]=n;
    while(i&&minheap->list[i]<minheap->list[(i-1)/2])
    {
        swap(&minheap->list[i],&minheap->list[(i-1)/2]);
        i=(i-1)/2;
    }
}

static inline void pop(struct heap* minheap)
{
    minheap->size--;
    minheap->list[0]=minheap->list[minheap->size];
    heapify(minheap,0);
}

static inline int top(struct heap* minheap)
{
    return minheap->list[0];
}

static inline void clear(struct heap* h)
{
    free(h->list);
    free(h);
}

int cmp(const void* p1,const void* p2)
{
    return (*(int**)p1)[0]-(*(int**)p2)[0];
}

int maxEvents(int** events, int n, int* eventsColSize)
{
    int i,j;
    int m=0,ans=0;
    struct heap* pq=initialize(10);
    qsort(events,n,sizeof(int*),cmp);
    for(i=0;i<n;i++)
    {
        m=max(m,events[i][1]);
    }
    for(i=0,j=0;i<=m;i++)
    {
        while(j<n&&events[j][0]<=i)
        {
            push(pq,events[j][1]);
            j++;
        }
        while(!empty(pq)&&top(pq)<i)
        {
            pop(pq);
        }
        if(!empty(pq))
        {
            pop(pq);
            ans++;
        }
    }
    clear(pq);
    return ans;
}
