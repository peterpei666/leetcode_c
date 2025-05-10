#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

struct node
{
    int x;
    int y;
    int t;
};

struct heap
{
    struct node* list;
    int size;
    int capacity;
};

struct heap* initialize(int n)
{
    struct heap* h=(struct heap*)malloc(sizeof(struct heap));
    h->size=0;
    h->capacity=n;
    h->list=(struct node*)malloc(sizeof(struct node)*n);
    return h;
}

inline void swap(struct node* a,struct node* b)
{
    struct node t=*a;
    *a=*b;
    *b=t;
}

void heapify(struct heap* heap,int i)
{
    int smallest=i;
    int l,r;
    while(1)
    {
        l=2*i+1;
        r=2*i+2;
        if(l<heap->size&&heap->list[l].t<heap->list[smallest].t)
        {
            smallest=l;
        }
        if(r<heap->size&&heap->list[r].t<heap->list[smallest].t)
        {
            smallest=r;
        }
        if(i==smallest)
        {
            break;
        }
        swap(&heap->list[i],&heap->list[smallest]);
        i=smallest;
    }
}

void insert(struct heap* heap,struct node input)
{
    if(heap->size>=heap->capacity)
    {
        heap->capacity*=2;
        heap->list=(struct node*)realloc(heap->list,sizeof(struct node)*heap->capacity);
    }
    int i=heap->size;
    heap->size++;
    heap->list[i]=input;
    while(i&&heap->list[i].t<heap->list[(i-1)/2].t)
    {
        swap(&heap->list[i],&heap->list[(i-1)/2]);
        i=(i-1)/2;
    }
}

void pop(struct heap* heap)
{
    heap->size--;
    heap->list[0]=heap->list[heap->size];
    heapify(heap,0);
}

struct node top(struct heap* maxheap)
 {
     return maxheap->list[0];
 }
 
void clear(struct heap* h)
{
    free(h->list);
    free(h);
}

int minTimeToReach(int** moveTime, int moveTimeSize, int* moveTimeColSize)
{
    int m,n,x,y,t,nx,ny,dist,i,j;
    int d[50][50];
    int dir[4][2]={-1,0,0,-1,0,1,1,0};
    unsigned char visited[50][10]={0};
    struct node temp;
    const int INF=2e9;
    m=moveTimeSize;
    n=moveTimeColSize[0];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            d[i][j]=INF;
        }
    }
    struct heap* minheap=initialize(m*n);
    insert(minheap,(struct node){0,0,0});
    while(minheap->size)
    {
        temp=top(minheap);
        pop(minheap);
        x=temp.x;
        y=temp.y;
        t=temp.t;
        if(visited[x][y>>3]&(1<<(y&7)))
        {
            continue;
        }
        visited[x][y>>3]|=1<<(y&7);
        for(i=0;i<4;i++)
        {
            nx=x+dir[i][0];
            ny=y+dir[i][1];
            if(nx>=0&&nx<m&&ny>=0&&ny<n)
            {
                dist=maxi(t,moveTime[nx][ny])+1;
                if(dist<d[nx][ny])
                {
                    d[nx][ny]=dist;
                    insert(minheap,(struct node){nx,ny,dist});
                }
            }
        }
    }
    return d[m-1][n-1];
}
