#include <stdio.h>
#include <stdlib.h>

inline long long maxi(long long a,long long b)
{
    return a>b?a:b;
}

inline long long mini(long long a,long long b)
{
    return a<b?a:b;
}

struct heap
{
    long long* list;
    int size;
    int capacity;
};

struct heap* initialize(int n)
{
    struct heap* h=(struct heap*)malloc(sizeof(struct heap));
    h->size=0;
    h->capacity=n;
    h->list=(long long*)malloc(sizeof(long long)*n);
    return h;
}

inline void swap(long long* a,long long* b)
{
    long long t=*a;
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

void push(struct heap* minheap,long long n)
{
    if(minheap->size>=minheap->capacity)
    {
        minheap->capacity*=2;
        minheap->list=(long long*)realloc(minheap->list,sizeof(long long)*minheap->capacity);
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

long long top(struct heap* minheap)
{
    return minheap->list[0];
}

void clear(struct heap* h)
{
    free(h->list);
    free(h);
}

int minOperations(int* nums, int n1, int k)
{
    int i,c=0;
    long long m,n;
    struct heap* minheap=initialize(n1);
    for(i=0;i<n1;i++)
    {
        push(minheap,nums[i]);
    }
    while(minheap->size>=2&&top(minheap)<k)
    {
        m=top(minheap);
        pop(minheap);
        n=top(minheap);
        pop(minheap);
        push(minheap,2*mini(m,n)+maxi(m,n));
        c++;
    }
    return c;
}
