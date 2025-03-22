#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INF 1000000

int directions[4][2]={-1,0,1,0,0,-1,0,1};

typedef struct
{
    int x;
    int y;
    int effort;
} node;

typedef struct
{
    node* list;
    int size;
    int capacity;
} heapnode;

void swap(node* a,node* b)
{
    node temp=*a;
    *a=*b;
    *b=temp;
}

void initialize_heap(heapnode* heap)
{
    heap->capacity=10;
    heap->size=0;
    heap->list=(node*)malloc(heap->capacity*sizeof(node));
}

void heapify(heapnode* heap,int i)
{
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<heap->size&&heap->list[smallest].effort>heap->list[left].effort)
    {
        smallest=left;
    }
    if(right<heap->size&&heap->list[smallest].effort>heap->list[right].effort)
    {
        smallest=right;
    }
    if(smallest!=i)
    {
        swap(&heap->list[smallest],&heap->list[i]);
        heapify(heap,smallest);
    }
}

void change_capacity(heapnode* heap)
{
    int c=((heap->size+2)/10+1)*10;
    if(c!=heap->capacity)
    {
        heap->list=(node*)realloc(heap->list,c*sizeof(node));
        heap->capacity=c;
    }
}

node extract(heapnode* heap)
{
    heap->size--;
    node temp=heap->list[0];
    heap->list[0]=heap->list[heap->size];
    change_capacity(heap);
    heapify(heap,0);
    return temp;
}

void insert(heapnode* heap,int x,int y,int effort)
{
    int i=heap->size;
    heap->size++;
    change_capacity(heap);
    heap->list[i]=(node){x,y,effort};
    while(i&&heap->list[i].effort<heap->list[(i-1)/2].effort)
    {
        swap(&heap->list[i],&heap->list[(i-1)/2]);
        i=(i-1)/2;
    }
}

int dijkstra(int** heights,int heightsSize,int* heightsColSize)
{
    int i,j,x,y,d,nx,ny,effort,new,max,ret=-1;
    node min;
    int** dist=(int**)malloc(heightsSize*sizeof(int*));
    heapnode heap;
    initialize_heap(&heap);
    for(i=0;i<heightsSize;i++)
    {
        dist[i]=(int*)malloc(heightsColSize[i]*sizeof(int));
        for(j=0;j<heightsColSize[i];j++)
        {
            dist[i][j]=INF;
        }
    }
    dist[0][0]=0;
    insert(&heap,0,0,0);
    while(heap.size)
    {
        min=extract(&heap);
        x=min.x;
        y=min.y;
        effort=min.effort;
        if(x==heightsSize-1&&y==heightsColSize[heightsSize-1]-1)
        {
            ret=effort;
            break;
        }
        for(d=0;d<4;d++)
        {
            nx=x+directions[d][0];
            ny=y+directions[d][1];
            if(nx>=0&&nx<heightsSize&&ny>=0&&ny<heightsColSize[nx])
            {
                new=abs(heights[nx][ny]-heights[x][y]);
                max=(new>effort)?new:effort;
                if(max<dist[nx][ny])
                {
                    dist[nx][ny]=max;
                    insert(&heap,nx,ny,max);
                }
            }
        }
    }
    for(i=0;i<heightsSize;i++)
    {
        free(dist[i]);
    }
    free(dist);
    free(heap.list);
    return ret;
}

int minimumEffortPath(int** heights, int heightsSize, int* heightsColSize)
{
    return dijkstra(heights,heightsSize,heightsColSize);
}
