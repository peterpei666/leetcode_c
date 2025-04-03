#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int direction[4][2]={-1,0,1,0,0,-1,0,1};

typedef struct
{
    int x;
    int y;
    int count;
} node;

typedef struct
{
    node* heap;
    int size;
    int capacity;
} heapnode;

heapnode minheap;

void initialize(void)
{
    minheap.heap=(node*)malloc(sizeof(node)*10);
    minheap.size=0;
    minheap.capacity=10;
}

void changesize(void)
{
    if(minheap.size>=minheap.capacity-2)
    {
        minheap.capacity*=2;
        minheap.heap=(node*)realloc(minheap.heap,minheap.capacity*sizeof(node));
    }
}

void swap(node* a,node* b)
{
    node temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int i)
{
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<minheap.size&&minheap.heap[smallest].count>minheap.heap[left].count)
    {
        smallest=left;
    }
    if(right<minheap.size&&minheap.heap[smallest].count>minheap.heap[right].count)
    {
        smallest=right;
    }
    if(smallest!=i)
    {
        swap(&minheap.heap[smallest],&minheap.heap[i]);
        heapify(smallest);
    }
}

void insert(int x,int y,int count)
{
    int i=minheap.size;
    minheap.heap[i]=(node){x,y,count};
    minheap.size++;
    changesize();
    while(i&&minheap.heap[i].count<minheap.heap[(i-1)/2].count)
    {
        swap(&minheap.heap[i],&minheap.heap[(i-1)/2]);
        i=(i-1)/2;
    }
}

node extract(void)
{
    node temp=minheap.heap[0];
    minheap.size--;
    minheap.heap[0]=minheap.heap[minheap.size];
    heapify(0);
    return temp;
}

int minimumObstacles(int** grid, int gridSize, int* gridColSize)
{
    int x,y,nx,ny,count=0,d,i;
    node temp;
    initialize();
    insert(0,0,0);
    bool* visited=(bool*)malloc(sizeof(bool)*gridSize*gridColSize[0]);
    memset(visited,false,gridSize*gridColSize[0]);
    while(minheap.size>0)
    {
        temp=extract();
        x=temp.x;
        y=temp.y;
        count=temp.count;
        if(x==gridSize-1&&y==gridColSize[x]-1)
        {
            break;
        }
        for(d=0;d<4;d++)
        {
            nx=x+direction[d][0];
            ny=y+direction[d][1];
            if(nx>=0&&nx<gridSize&&ny>=0&&ny<gridColSize[nx]&&visited[nx*gridColSize[0]+ny]==false)
            {
                visited[nx*gridColSize[0]+ny]=true;
                if(grid[nx][ny]==0)
                {
                    insert(nx,ny,count);
                }
                if(grid[nx][ny]==1)
                {
                    insert(nx,ny,count+1);
                }
            }
        }
    }
    free(visited);
    free(minheap.heap);
    minheap.heap=NULL;
    return count;
}
