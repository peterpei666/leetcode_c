#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
    int w;
} node;

struct heap
{
    node* list;
    int size;
    int capacity;
};

struct heap* initialize(int n)
{
    struct heap* h=(struct heap*)malloc(sizeof(struct heap));
    h->size=0;
    h->capacity=n;
    h->list=(node*)malloc(sizeof(node)*n);
    return h;
}

inline void swap(node* a,node* b)
{
    node t=*a;
    *a=*b;
    *b=t;
}

void heapify(struct heap* minheap,int i)
{
    int smallest=i;
    int l,r;
    while(1)
    {
        l=2*i+1;
        r=2*i+2;
        if(l<minheap->size&&minheap->list[l].w<minheap->list[smallest].w)
        {
            smallest=l;
        }
        if(r<minheap->size&&minheap->list[r].w<minheap->list[smallest].w)
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

void push(struct heap* minheap,node n)
{
    if(minheap->size>=minheap->capacity)
    {
        minheap->capacity*=2;
        minheap->list=(node*)realloc(minheap->list,sizeof(node)*minheap->capacity);
    }
    int i=minheap->size;
    minheap->size++;
    minheap->list[i]=n;
    while(i&&minheap->list[i].w<minheap->list[(i-1)/2].w)
    {
        swap(&minheap->list[i],&minheap->list[(i-1)/2]);
        i=(i-1)/2;
    }
}

void pop(struct heap* minheap)
{
    minheap->size--;
    minheap->list[0]=minheap->list[minheap->size];
    heapify(minheap,0);
}

node top(struct heap* minheap)
{
    return minheap->list[0];
}

void clear(struct heap* h)
{
    free(h->list);
    free(h);
}

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int maxDistance(int** grid, int n, int* gridColSize)
{
    int x,y,nx,ny,d,dis=0;
    int dir[4][2]={-1,0,0,-1,0,1,1,0};
    node temp;
    struct heap* minheap=initialize(n);
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
        {
            if(grid[x][y]==0)
            {
                grid[x][y]=10000;
            }
            else
            {
                grid[x][y]=0;
                push(minheap,(node){x,y,0});
            }
        }
    }
    while(minheap->size)
    {
        temp=top(minheap);
        x=temp.x;
        y=temp.y;
        pop(minheap);
        for(d=0;d<4;d++)
        {
            nx=x+dir[d][0];
            ny=y+dir[d][1];
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&grid[x][y]+1<grid[nx][ny])
            {
                grid[nx][ny]=grid[x][y]+1;
                push(minheap,(node){nx,ny,grid[nx][ny]});
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dis=maxi(dis,grid[i][j]);
        }
    }
    if(dis==0||dis==10000)
    {
        return -1;
    }
    return dis;
}
