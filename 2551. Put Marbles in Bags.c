#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int* heap;
    int size;
} heapnode;

heapnode minheap;
heapnode maxheap;

void insert_min(int x)
{
    int i=minheap.size,temp;
    minheap.size++;
    minheap.heap[i]=x;
    while(i&&minheap.heap[(i-1)/2]>minheap.heap[i])
    {
        temp=minheap.heap[(i-1)/2];
        minheap.heap[(i-1)/2]=minheap.heap[i];
        minheap.heap[i]=temp;
        i=(i-1)/2;
    }
}

void insert_max(int x)
{
    int i=maxheap.size,temp;
    maxheap.size++;
    maxheap.heap[i]=x;
    while(i&&maxheap.heap[(i-1)/2]<maxheap.heap[i])
    {
        temp=maxheap.heap[(i-1)/2];
        maxheap.heap[(i-1)/2]=maxheap.heap[i];
        maxheap.heap[i]=temp;
        i=(i-1)/2;
    }
}

void heapify_min(int i)
{
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    int temp;
    if(left<minheap.size&&minheap.heap[left]<minheap.heap[smallest])
    {
        smallest=left;
    }
    if(right<minheap.size&&minheap.heap[right]<minheap.heap[smallest])
    {
        smallest=right;
    }
    if(i!=smallest)
    {
        temp=minheap.heap[smallest];
        minheap.heap[smallest]=minheap.heap[i];
        minheap.heap[i]=temp;
        heapify_min(smallest);
    }
}

void heapify_max(int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    int temp;
    if(left<maxheap.size&&maxheap.heap[left]>maxheap.heap[largest])
    {
        largest=left;
    }
    if(right<maxheap.size&&maxheap.heap[right]>maxheap.heap[largest])
    {
        largest=right;
    }
    if(i!=largest)
    {
        temp=maxheap.heap[largest];
        maxheap.heap[largest]=maxheap.heap[i];
        maxheap.heap[i]=temp;
        heapify_max(largest);
    }
}

void extract_min(void)
{
    minheap.size--;
    minheap.heap[0]=minheap.heap[minheap.size];
    heapify_min(0);
}

void extract_max(void)
{
    maxheap.size--;
    maxheap.heap[0]=maxheap.heap[maxheap.size];
    heapify_max(0);
}

void initialize(heapnode* h,int k)
{
    h->heap=(int*)malloc(sizeof(int)*k);
    h->size=0;
}

void clear(heapnode* h)
{
    free(h->heap);
    h->size=0;
}

long long putMarbles(int* weights, int weightsSize, int k)
{
    if(k==weightsSize||k==1)
    {
        return 0;
    }
    int i,temp;
    long long min=0,max=0;
    initialize(&minheap,k-1);
    initialize(&maxheap,k-1);
    for(i=0;i<k-1;i++)
    {
        temp=weights[i]+weights[i+1];
        insert_max(temp);
        insert_min(temp);
    }
    for(i=k-1;i<weightsSize-1;i++)
    {
        temp=weights[i]+weights[i+1];
        if(temp>minheap.heap[0])
        {
            extract_min();
            insert_min(temp);
        }
        if(temp<maxheap.heap[0])
        {
            extract_max();
            insert_max(temp);
        }
    }
    for(i=0;i<k-1;i++)
    {
        min+=maxheap.heap[i];
        max+=minheap.heap[i];
    }
    clear(&minheap);
    clear(&maxheap);
    return max-min;
}
