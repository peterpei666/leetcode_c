#include <stdio.h>
#include <stdlib.h>

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
 
void heapify_min(heap* minheap,int i)
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

void push_min(heap* minheap,int n)
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

static inline void pop_min(heap* minheap)
{
    minheap->size--;
    minheap->list[0]=minheap->list[minheap->size];
    heapify_min(minheap,0);
}

typedef struct
{
    heap* maxheap;
    heap* minheap;
} MedianFinder;


MedianFinder* medianFinderCreate(void)
{
    MedianFinder* obj=(MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxheap=initialize(16);
    obj->minheap=initialize(16);
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num)
{
    push_max(obj->maxheap,num);
    push_min(obj->minheap,top(obj->maxheap));
    pop_max(obj->maxheap);
    if(obj->maxheap->size<obj->minheap->size)
    {
        push_max(obj->maxheap,top(obj->minheap));
        pop_min(obj->minheap);
    }
}

double medianFinderFindMedian(MedianFinder* obj)
{
    if(obj->maxheap->size>obj->minheap->size)
    {
        return top(obj->maxheap);
    }
    return (top(obj->maxheap)+top(obj->minheap))/2.0;
}

void medianFinderFree(MedianFinder* obj)
{
    clear(obj->maxheap);
    clear(obj->minheap);
    free(obj);
}
