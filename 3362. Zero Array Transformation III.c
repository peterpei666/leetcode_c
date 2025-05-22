#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int cmp(const void* p1,const void* p2)
{
    int** a=(int**)p1;
    int** b=(int**)p2;
    return (*a)[0]-(*b)[0];
}

int maxRemoval(int* nums, int n, int** queries, int q, int* queriesColSize)
{
    int i,j,cnt=0;
    int delta[n+1];
    struct heap* maxheap=initialize(q/2+1);
    memset(delta,0,sizeof(delta));
    qsort(queries,q,sizeof(int*),cmp);
    for(i=0,j=0;i<n;i++)
    {
        cnt+=delta[i];
        while(j<q&&queries[j][0]==i)
        {
            push(maxheap,queries[j][1]);
            j++;
        }
        while(cnt<nums[i]&&maxheap->size&&top(maxheap)>=i)
        {
            cnt++;
            delta[top(maxheap)+1]--;
            pop(maxheap);
        }
        if(cnt<nums[i])
        {
            return -1;
        }
    }
    cnt=maxheap->size;
    clear(maxheap);
    return cnt;
}
