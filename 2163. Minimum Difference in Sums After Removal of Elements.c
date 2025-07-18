#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static inline long long min(long long a,long long b)
{
    return a<b?a:b;
}

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
 
static inline void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

static inline int top(struct heap* heap)
{
    return heap->list[0];
}

static inline void clear(struct heap* h)
{
    free(h->list);
    free(h);
}

void heapify_min(struct heap* minheap,int i)
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

void push_min(struct heap* minheap,int n)
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

static inline void pop_min(struct heap* minheap)
{
    minheap->size--;
    minheap->list[0]=minheap->list[minheap->size];
    heapify_min(minheap,0);
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

void push_max(struct heap* maxheap,int n)
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
 
static inline void pop_max(struct heap* maxheap)
{
    maxheap->size--;
    maxheap->list[0]=maxheap->list[maxheap->size];
    heapify_max(maxheap,0);
}

long long minimumDifference(int* nums, int numsSize)
{
    int n=numsSize/3;
    long long sum1=0;
    struct heap* pq1=initialize(n+1);
    for(int i=0;i<n;i++)
    {
        push_max(pq1,nums[i]);
        sum1+=nums[i];
    }
    long long left[n+1];
    left[0]=sum1;
    for(int i=n;i<2*n;i++)
    {
        push_max(pq1,nums[i]);
        sum1+=nums[i]-top(pq1);
        pop_max(pq1);
        left[i-n+1]=sum1;
    }
    clear(pq1);
    struct heap* pq2=initialize(n+1);
    long long sum2=0;
    for(int i=3*n-1;i>=2*n;i--)
    {
        push_min(pq2,nums[i]);
        sum2+=nums[i];
    }
    long long ans=left[n]-sum2;
    for(int i=2*n-1;i>=n;i--)
    {
        push_min(pq2,nums[i]);
        sum2+=nums[i]-top(pq2);
        pop_min(pq2);
        ans=min(ans,left[i-n]-sum2);
    }
    clear(pq2);
    return ans;
}
