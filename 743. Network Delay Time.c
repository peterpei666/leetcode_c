#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INF 1000000

typedef struct
{
    int vertex;
    int weight;
} edge;

typedef struct
{
    edge* e;
    int size;
    int capacity;
} heapnode;

void swap(edge* a,edge* b)
{
    edge temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(heapnode* heap,int i)
{
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<heap->size&&heap->e[left].weight<heap->e[smallest].weight)
    {
        smallest=left;
    }
    if(right<heap->size&&heap->e[right].weight<heap->e[smallest].weight)
    {
        smallest=right;
    }
    if(i!=smallest)
    {
        swap(&heap->e[i],&heap->e[smallest]);
        heapify(heap,smallest);
    }
}

edge extract(heapnode* heap)
{
    edge temp=heap->e[0];
    heap->size--;
    heap->e[0]=heap->e[heap->size];
    heapify(heap,0);
    return temp;
}

void insert(heapnode* heap,edge e)
{
    int i=heap->size;
    heap->size++;
    heap->e[i]=e;
    while(i&&heap->e[(i-1)/2].weight>heap->e[i].weight)
    {
        swap(&heap->e[(i-1)/2],&heap->e[i]);
        i=(i-1)/2;
    }
}

void intoboard(int*** board,int n,int** times,int timesSize)
{
    int i,j,u,v,w;
    *board=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        (*board)[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                (*board)[i][j]=0;
            }
            else
            {
                (*board)[i][j]=INF;
            }
        }
    }
    for(i=0;i<timesSize;i++)
    {
        u=times[i][0];
        v=times[i][1];
        w=times[i][2];
        (*board)[u-1][v-1]=w;
    }
}

int dijkstra(int** board,int n,int source)
{
    int i,u,v,max;
    int* dist=(int*)malloc(n*sizeof(int));
    bool* visited=(bool*)malloc(n*sizeof(bool));
    edge min;
    heapnode heap;
    memset(visited,false,sizeof(bool)*n);
    heap.e=(edge*)malloc(n*n*sizeof(edge));
    heap.size=0;
    heap.capacity=n*n;
    for(i=0;i<n;i++)
    {
        dist[i]=INF;
    }
    dist[source-1]=0;
    insert(&heap,(edge){source-1,0});
    while(heap.size>0)
    {
        min=extract(&heap);
        u=min.vertex;
        if(visited[u])
        {
            continue;
        }
        visited[u]=true;
        for(v=0;v<n;v++)
        {
            if(visited[v]==false&&board[u][v]!=INF&&dist[u]!=INF&&dist[v]>dist[u]+board[u][v])
            {
                dist[v]=dist[u]+board[u][v];
                insert(&heap,(edge){v,dist[v]});
            }
        }
    }
    max=dist[0];
    for(i=1;i<n;i++)
    {
        if(dist[i]>max)
        {
            max=dist[i];
        }
    }
    for(i=0;i<n;i++)
    {
        free(board[i]);
    }
    free(board);
    free(heap.e);
    if(max==INF)
    {
        return -1;
    }
    return max;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k)
{
    int** board=NULL;
    intoboard(&board,n,times,timesSize);
    return dijkstra(board,n,k);
}
