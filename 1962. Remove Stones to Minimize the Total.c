#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int* list;
    int size;
} maxheap;

inline void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void initialize(maxheap* heap,int size)
{
    heap->size=0;
    heap->list=(int*)malloc(sizeof(int)*size);
}

void insert(maxheap* heap,int num)
{
    int i=heap->size;
    heap->size++;
    heap->list[i]=num;
    while(i&&heap->list[i]>heap->list[(i-1)/2])
    {
        swap(&heap->list[i],&heap->list[(i-1)/2]);
        i=(i-1)/2;
    }
}

void heapify(maxheap* heap,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<heap->size&&heap->list[largest]<heap->list[left])
    {
        largest=left;
    }
    if(right<heap->size&&heap->list[largest]<heap->list[right])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(&heap->list[i],&heap->list[largest]);
        heapify(heap,largest);
    }
}

void extract(maxheap* heap)
{
    heap->size--;
    heap->list[0]=heap->list[heap->size];
    heapify(heap,0);
}

int minStoneSum(int* piles, int pilesSize, int k)
{
    int i,temp,total=0;
    maxheap heap;
    initialize(&heap,pilesSize);
    for(i=0;i<pilesSize;i++)
    {
        total+=piles[i];
        insert(&heap,piles[i]);
    }
    while(k&&heap.list[0]!=1)
    {
        temp=heap.list[0];
        total-=temp/2;
        extract(&heap);
        insert(&heap,temp-temp/2);
        k--;
    }
    free(heap.list);
    return total;
}
