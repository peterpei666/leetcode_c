#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    double dif;
    int idx;
} pair;

typedef struct
{
    pair* list;
    int size;
    int capacity;
} heap;
 
heap* initialize(int n)
{
    heap* h=(heap*)malloc(sizeof(heap));
    h->size=0;
    h->capacity=n;
    h->list=(pair*)malloc(sizeof(pair)*n);
    return h;
}
 
static inline void swap(pair* a,pair* b)
{
    pair t=*a;
    *a=*b;
    *b=t;
}

static inline pair top(heap* h)
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
        if(l<maxheap->size&&maxheap->list[l].dif>maxheap->list[largest].dif)
        {
            largest=l;
        }
        if(r<maxheap->size&&maxheap->list[r].dif>maxheap->list[largest].dif)
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

void push_max(heap* maxheap, pair n)
{
    if(maxheap->size>=maxheap->capacity)
    {
        maxheap->capacity*=2;
        maxheap->list=(pair*)realloc(maxheap->list,sizeof(pair)*maxheap->capacity);
    }
    int i=maxheap->size;
    maxheap->size++;
    maxheap->list[i]=n;
    while(i&&maxheap->list[i].dif>maxheap->list[(i-1)/2].dif)
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

double maxAverageRatio(int** classes, int n, int* classesColSize, int extraStudents)
{
    heap* pq = initialize(n);
    for (int i = 0; i < n; i++)
    {
        double temp = (classes[i][0] + 1) / 1.0 / (classes[i][1] + 1) - classes[i][0] / 1.0 / classes[i][1];
        push_max(pq, (pair){temp, i});
    }
    while (extraStudents)
    {
        int id = top(pq).idx;
        pop_max(pq);
        classes[id][0]++;
        classes[id][1]++;
        extraStudents--;
        double temp = (classes[id][0] + 1) / 1.0 / (classes[id][1] + 1) - classes[id][0] / 1.0 / classes[id][1];
        push_max(pq, (pair){temp, id});
    }
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += classes[i][0] / 1.0 / classes[i][1];
    }
    return ans / n;
}
