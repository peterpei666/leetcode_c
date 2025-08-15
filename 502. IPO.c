#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int* list;
    int size;
    int capacity;
} heap;
 
heap* initialize(int n)
{
    heap* h=(heap*)malloc(sizeof(heap));
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

static inline int top(heap* h)
{
    return h->list[0];
}
 
static inline void clear(heap* h)
{
    free(h->list);
    free(h);
}

static inline bool empty(heap* h)
{
    return h->size==0;
}

void heapify_max(heap* maxheap,int i)
{
    int largest=i;
    int l,r;
    while(1)
    {
        l=2*i+1;
        r=2*i+2;
        if(l<maxheap->size&&maxheap->list[l]>maxheap->list[largest])
        {
            largest=l;
        }
        if(r<maxheap->size&&maxheap->list[r]>maxheap->list[largest])
        {
            largest=r;
        }
        if(i==largest)
        {
            break;
        }
        swap(&maxheap->list[i],&maxheap->list[largest]);
        i=largest;
    }
}

void push_max(heap* maxheap,int n)
{
    if(maxheap->size>=maxheap->capacity)
    {
        maxheap->capacity*=2;
        maxheap->list=(int*)realloc(maxheap->list,sizeof(int)*maxheap->capacity);
    }
    int i=maxheap->size;
    maxheap->size++;
    maxheap->list[i]=n;
    while(i&&maxheap->list[i]>maxheap->list[(i-1)/2])
    {
        swap(&maxheap->list[i],&maxheap->list[(i-1)/2]);
        i=(i-1)/2;
    }
}
 
static inline void pop_max(heap* maxheap)
{
    maxheap->size--;
    maxheap->list[0]=maxheap->list[maxheap->size];
    heapify_max(maxheap,0);
}

typedef struct
{
    int a;
    int b;
} pair;

int cmp(const void* p1,const void* p2)
{
    return ((pair*)p1)->a-((pair*)p2)->a;
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize)
{
    int n=profitsSize;
    pair list[n];
    for(int i=0;i<n;i++)
    {
        list[i]=(pair){capital[i],profits[i]};
    }
    qsort(list,n,sizeof(pair),cmp);
    heap* pq=initialize(n/2+1);
    int i=0;
    while(k)
    {
        while(i<n&&list[i].a<=w)
        {
            push_max(pq,list[i].b);
            i++;
        }
        if(empty(pq))
        {
            break;
        }
        w+=top(pq);
        pop_max(pq);
        k--;
    }
    clear(pq);
    return w;
}
