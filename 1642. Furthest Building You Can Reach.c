#include <stdio.h>
#include <stdlib.h>

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

void pop(struct heap* minheap)
{
    minheap->size--;
    minheap->list[0]=minheap->list[minheap->size];
    heapify(minheap,0);
}

 int top(struct heap* minheap)
 {
     return minheap->list[0];
 }
 
void clear(struct heap* h)
{
    free(h->list);
    free(h);
}

int furthestBuilding(int* heights, int n, int bricks, int ladders)
{
    int i,dif;
    struct heap* minheap=initialize(ladders+1);
    for(i=1;i<n;i++)
    {
        int dif=heights[i]-heights[i-1];
        if(dif<=0)
        {
            continue;
        }
        push(minheap,dif);
        if(minheap->size>ladders)
        {
            bricks-=top(minheap);
            pop(minheap);
            if(bricks<0)
            {
                return i-1;
            }
        }
    }
    return n-1;
}
