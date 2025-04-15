#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int cost;
    char direction;
} pair;

typedef struct
{
    pair* list;
    int size;
} maxheap;

void initialize(maxheap* heap,int m,int n)
{
    heap->size=0;
    heap->list=(pair*)malloc(sizeof(pair)*(m+n-2));
}

void swap(pair* a,pair* b)
{
    pair temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(maxheap* heap,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    int size=heap->size;
    if(left<size&&heap->list[left].cost>heap->list[largest].cost)
    {
        largest=left;
    }
    if(right<size&&heap->list[right].cost>heap->list[largest].cost)
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(&heap->list[i],&heap->list[largest]);
        heapify(heap,largest);
    }
}

void insert(maxheap* heap,int cost,char d)
{
    int i=heap->size;
    heap->size++;
    heap->list[i]=(pair){cost,d};
    while(i&&heap->list[(i-1)/2].cost<heap->list[i].cost)
    {
        swap(&heap->list[(i-1)/2],&heap->list[i]);
        i=(i-1)/2;
    }
}

pair extract(maxheap* heap)
{
    pair temp=heap->list[0];
    heap->size--;
    heap->list[0]=heap->list[heap->size];
    heapify(heap,0);
    return temp;
}

int minimumCost(int m, int n, int* horizontalCut, int horizontalCutSize, int* verticalCut, int verticalCutSize)
{
    int i,count=0,h=1,v=1;
    pair temp;
    maxheap heap;
    initialize(&heap,m,n);
    for(i=0;i<horizontalCutSize;i++)
    {
        insert(&heap,horizontalCut[i],'H');
    }
    for(i=0;i<verticalCutSize;i++)
    {
        insert(&heap,verticalCut[i],'V');
    }
    while(heap.size)
    {
        temp=extract(&heap);
        if(temp.direction=='H')
        {
            count+=temp.cost*h;
            v++;
        }
        else
        {
            count+=temp.cost*v;
            h++;
        }
    }
    free(heap.list);
    return count;
}
