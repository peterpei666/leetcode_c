#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct heap
{
    int* list;
    int size;
    int capacity;
};

struct heap* initialize(int n)
{
    struct heap* h=(struct heap*)malloc(sizeof(struct heap));
    h->size=0;
    h->capacity=n;
    h->list=(int*)malloc(sizeof(int)*n);
    return h;
}

inline void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void heapify(struct heap* maxheap,int i)
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

void push(struct heap* maxheap,int n)
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

 void pop(struct heap* maxheap)
 {
     maxheap->size--;
     maxheap->list[0]=maxheap->list[maxheap->size];
     heapify(maxheap,0);
 }

 int top(struct heap* maxheap)
 {
     return maxheap->list[0];
 }
 
void clear(struct heap* h)
{
    free(h->list);
    free(h);
}

int lastStoneWeight(int* stones, int n)
{
    int i,m1,m2;
    struct heap* maxheap=initialize(n);
    for(i=0;i<n;i++)
    {
        push(maxheap,stones[i]);
    }
    while(maxheap->size>1)
    {
        m1=top(maxheap);
        pop(maxheap);
        m2=top(maxheap);
        pop(maxheap);
        m1-=m2;
        if(m1||maxheap->size==0)
        {
            push(maxheap,m1);
        }
    }
    m1=top(maxheap);
    clear(maxheap);
    return m1;
}

