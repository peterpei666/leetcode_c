#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INF 100000000000000
#define M 1000000007

typedef struct
{
    int vertex;
    long long weight;
} edge;

typedef struct
{
    edge* list;
    int size;
    int capacity;
} heapnode;

void swap(edge* a,edge* b)
{
    edge temp=*a;
    *a=*b;
    *b=temp;
}

void change_capacity(heapnode* heap)
{
    int c=(heap->size+12)/10*10;
    if(c!=heap->capacity)
    {
        heap->capacity=c;
        heap->list=(edge*)realloc(heap->list,c*sizeof(edge));
    }
}

void initialize(heapnode* heap)
{
    heap->size=0;
    heap->capacity=10;
    heap->list=(edge*)malloc(10*sizeof(edge));
}

void heapify(heapnode* heap,int i)
{
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<heap->size&&heap->list[left].weight<heap->list[smallest].weight)
    {
        smallest=left;
    }
    if(right<heap->size&&heap->list[right].weight<heap->list[smallest].weight)
    {
        smallest=right;
    }
    if(smallest!=i)
    {
        swap(&heap->list[i],&heap->list[smallest]);
        heapify(heap,smallest);
    }
}

edge extract(heapnode* heap)
{
    edge temp=heap->list[0];
    heap->size--;
    heap->list[0]=heap->list[heap->size];
    change_capacity(heap);
    heapify(heap,0);
    return temp;
}

void insert(heapnode* heap,edge e)
{
    int i=heap->size;
    heap->size++;
    heap->list[i]=e;
    change_capacity(heap);
    while(i&&heap->list[(i-1)/2].weight>heap->list[i].weight)
    {
        swap(&heap->list[(i-1)/2],&heap->list[i]);
        i=(i-1)/2;
    }
}

void form(edge*** board,int n,int* nums,int** roads,int roadsSize)
{
    int i,u,v,w;
    *board=(edge**)malloc(n*sizeof(edge*));
    for(i=0;i<n;i++)
    {
        nums[i]=0;
        (*board)[i]=(edge*)malloc(sizeof(edge));
    }
    for(i=0;i<roadsSize;i++)
    {
        u=roads[i][0];
        v=roads[i][1];
        w=roads[i][2];
        (*board)[u][nums[u]]=(edge){v,(long long)w};
        nums[u]++;
        (*board)[u]=(edge*)realloc((*board)[u],(nums[u]+1)*sizeof(edge));
        (*board)[v][nums[v]]=(edge){u,(long long)w};
        nums[v]++;
        (*board)[v]=(edge*)realloc((*board)[v],(nums[v]+1)*sizeof(edge));
    }
}

int countPaths(int n, int** roads, int roadsSize, int* roadsColSize)
{
    int i,j,u,v,temp;
    long long w;
    edge min;
    long long* dist=(long long*)malloc(n*sizeof(long long));
    int* ways=(int*)calloc(n,sizeof(int));
    int* nums=(int*)malloc(n*sizeof(int));
    bool* visited=(bool*)malloc(n*sizeof(bool));
    edge** board=NULL;
    heapnode heap;
    memset(visited,false,n*sizeof(bool));
    form(&board,n,nums,roads,roadsSize);
    initialize(&heap);
    insert(&heap,(edge){0,0});
    ways[0]=1;
    dist[0]=0;
    for(i=1;i<n;i++)
    {
        dist[i]=INF;
    }
    while(heap.size)
    {
        min=extract(&heap);
        u=min.vertex;
        if(visited[u])
        {
            continue;
        }
        visited[u]=true;
        for(i=0;i<nums[u];i++)
        {
            v=board[u][i].vertex;
            w=board[u][i].weight;
            if(visited[v]==false&&dist[u]!=INF)
            {
                if(dist[u]+w<dist[v])
                {
                    dist[v]=dist[u]+w;
                    ways[v]=ways[u];
                    insert(&heap,(edge){v,dist[v]});
                }
                else if(dist[u]+w==dist[v])
                {
                    ways[v]+=ways[u];
                    ways[v]%=M;
                    insert(&heap,(edge){v,dist[v]});
                }
            }
        }
    }
    if(dist[n-1]==INF)
    {
        temp=-1;
    }
    else
    {
        temp=ways[n-1];
    }
    free(dist);
    free(nums);
    free(ways);
    free(visited);
    for(i=0;i<n;i++)
    {
        free(board[i]);
    }
    free(board);
    return temp;
}
