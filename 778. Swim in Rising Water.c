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
    int time;
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

void initialize(heapnode* heap)
{
    heap->size=0;
    heap->capacity=10;
    heap->list=(node*)malloc(heap->capacity*sizeof(node));
}

void change_capacity(heapnode* heap)
{
    int c=(heap->size+12)/10*10;
    if(c!=heap->capacity)
    {
        heap->capacity=c;
        heap->list=(node*)realloc(heap->list,c*sizeof(node));
    }
}

void heapify(heapnode* heap,int i)
{
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<heap->size&&heap->list[left].time<heap->list[smallest].time)
    {
        smallest=left;
    }
    if(right<heap->size&&heap->list[right].time<heap->list[smallest].time)
    {
        smallest=right;
    }
    if(smallest!=i)
    {
        swap(&heap->list[i],&heap->list[smallest]);
        heapify(heap,smallest);
    }
}

node extract(heapnode* heap)
{
    node temp=heap->list[0];
    heap->size--;
    change_capacity(heap);
    heap->list[0]=heap->list[heap->size];
    heapify(heap,0);
    return temp;
}

void insert(heapnode* heap,node n)
{
    int i=heap->size;
    heap->size++;
    change_capacity(heap);
    heap->list[i]=n;
    while(i&&heap->list[i].time<heap->list[(i-1)/2].time)
    {
        swap(&heap->list[i],&heap->list[(i-1)/2]);
        i=(i-1)/2;
    }
}

int swimInWater(int** grid, int gridSize, int* gridColSize)
{
    int i,j,x,y,nx,ny,new,d,t,ans=INF;
    heapnode heap;
    node min;
    bool** visited=(bool**)malloc(gridSize*sizeof(bool*));
    for(i=0;i<gridSize;i++)
    {
        visited[i]=(bool*)malloc(gridColSize[i]*sizeof(bool));
        memset(visited[i],false,gridColSize[i]*sizeof(bool));
    }
    int** time=(int**)malloc(gridSize*sizeof(int*));
    for(i=0;i<gridSize;i++)
    {
        time[i]=(int*)malloc(gridColSize[i]*sizeof(int));
        for(j=0;j<gridColSize[i];j++)
        {
            time[i][j]=INF;
        }
    }
    time[0][0]=0;
    initialize(&heap);
    insert(&heap,(node){0,0,grid[0][0]});
    while(heap.size)
    {
        min=extract(&heap);
        x=min.x;
        y=min.y;
        t=min.time;
        if(x==gridSize-1&&y==gridColSize[gridSize-1]-1)
        {
            ans=t;
            break;
        }
        if(visited[x][y])
        {
            continue;
        }
        visited[x][y]=true;
        time[x][y]=t;
        for(d=0;d<4;d++)
        {
            nx=x+directions[d][0];
            ny=y+directions[d][1];
            if(nx>=0&&nx<gridSize&&ny>=0&&ny<gridColSize[gridSize-1]&&visited[nx][ny]==false)
            {
                new=(time[x][y]>grid[nx][ny])?time[x][y]:grid[nx][ny];
                insert(&heap,(node){nx,ny,new});
            }
        }
    }
    for(i=0;i<gridSize;i++)
    {
        free(visited[i]);
        free(time[i]);
    }
    free(visited);
    free(time);
    if(ans==INF)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}
