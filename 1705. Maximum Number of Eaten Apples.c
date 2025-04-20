#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int apple;
    int day;
} node;

typedef struct
{
    node* heap;
    int size;
    int capacity;
} heapnode;

inline void swap(node* a,node* b)
{
    node temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(heapnode* minheap,int i)
{
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<minheap->size&&minheap->heap[left].day<minheap->heap[smallest].day)
    {
        smallest=left;
    }
    if(right<minheap->size&&minheap->heap[right].day<minheap->heap[smallest].day)
    {
        smallest=right;
    }
    if(smallest!=i)
    {
        swap(&minheap->heap[smallest],&minheap->heap[i]);
        heapify(minheap,smallest);
    }
}

void insert(heapnode* minheap,int apple,int day)
{
    int i=minheap->size;
    minheap->size++;
    minheap->heap[i]=(node){apple,day};
    while(i&&minheap->heap[i].day<minheap->heap[(i-1)/2].day)
    {
        swap(&minheap->heap[i],&minheap->heap[(i-1)/2]);
        i=(i-1)/2;
    }
}

void extract(heapnode* minheap)
{
    minheap->size--;
    minheap->heap[0]=minheap->heap[minheap->size];
    heapify(minheap,0);
}

int eatenApples(int* apples, int applesSize, int* days, int daysSize)
{
    int d=0,count=0;
    heapnode minheap;
    minheap.capacity=applesSize;
    minheap.heap=(node*)malloc(sizeof(node)*applesSize);
    minheap.size=0;
    while(d<applesSize||minheap.size)
    {
        if(d<applesSize&&apples[d])
        {
            insert(&minheap,apples[d],d+days[d]);
        }
        while(minheap.size&&(minheap.heap[0].day<=d||minheap.heap[0].apple<=0))
        {
            extract(&minheap);
        }
        if(minheap.size)
        {
            minheap.heap[0].apple--;
            count++;
        }
        d++;
    }
    free(minheap.heap);
    return count;
}
