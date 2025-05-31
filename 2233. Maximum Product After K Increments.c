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

int maximumProduct(int* nums, int n, int k)
{
    int i,temp;
    long long ret=1;
    const int mod=1e9+7;
    struct heap* pq=initialize(n);
    for(i=0;i<n;i++)
    {
        push(pq,nums[i]);
    }
    while(k)
    {
        temp=top(pq);
        pop(pq);
        push(pq,temp+1);
        k--;
    }
    while(pq->size)
    {
        ret*=top(pq);
        pop(pq);
        ret%=mod;
    }
    return ret%mod;
}
