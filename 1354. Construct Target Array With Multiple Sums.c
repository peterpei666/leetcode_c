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

void heapify_max(struct heap* maxheap,int i)
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

void insert_max(struct heap* maxheap,int n)
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

int extract_max(struct heap* maxheap)
{
    maxheap->size--;
    int ret=maxheap->list[0];
    maxheap->list[0]=maxheap->list[maxheap->size];
    heapify_max(maxheap,0);
    return ret;
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

bool isPossible(int* target, int targetSize)
{
    if(targetSize==1)
    {
        return target[0]==1;
    }
    int i,cur,x;
    long long sum=0;
    struct heap* maxheap=initialize(targetSize);
    for(i=0;i<targetSize;i++)
    {
        sum+=target[i];
        insert_max(maxheap,target[i]);
    }
    while(top(maxheap)!=1)
    {
        cur=top(maxheap);
        extract_max(maxheap);
        if(sum-cur==1)
        {
            clear(maxheap);
            return true;
        }
        x=cur%(sum-cur);
        sum=sum-cur+x;
        if(x==0||x==cur)
        {
            clear(maxheap);
            return false;
        }
        insert_max(maxheap,x);
    }
    clear(maxheap);
    return true;
}
