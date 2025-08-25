#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int h;
    int x;
    int y;
} T;

typedef struct
{
    T* list;
    int size;
    int capacity;
} heap;
 
heap* initialize(int n)
{
    heap* h=(heap*)malloc(sizeof(heap));
    h->size=0;
    h->capacity=n;
    h->list=(T*)malloc(sizeof(T)*n);
    return h;
}
 
static inline void swap(T* a,T* b)
{
    T t=*a;
    *a=*b;
    *b=t;
}

static inline T top(heap* h)
{
    return h->list[0];
}
 
static inline void clear(heap* h)
{
    free(h->list);
    free(h);
}

static inline bool empty(heap* h)
{
    return h->size==0;
}

void heapify_min(heap* minheap,int i)
{
    int smallest=i;
    int l,r;
    while(1)
    {
        l=2*i+1;
        r=2*i+2;
        if(l<minheap->size&&minheap->list[l].h<minheap->list[smallest].h)
        {
            smallest=l;
        }
        if(r<minheap->size&&minheap->list[r].h<minheap->list[smallest].h)
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

void push_min(heap* minheap,T n)
{
    if(minheap->size>=minheap->capacity)
    {
        minheap->capacity*=2;
        minheap->list=(T*)realloc(minheap->list,sizeof(T)*minheap->capacity);
    }
    int i=minheap->size;
    minheap->size++;
    minheap->list[i]=n;
    while(i&&minheap->list[i].h<minheap->list[(i-1)/2].h)
    {
        swap(&minheap->list[i],&minheap->list[(i-1)/2]);
        i=(i-1)/2;
    }
}

static inline void pop_min(heap* minheap)
{
    minheap->size--;
    minheap->list[0]=minheap->list[minheap->size];
    heapify_min(minheap,0);
}

#define N 200

typedef struct
{
    unsigned long long list[N/8+1];
} bitset;

static inline void reset_all(bitset* a)
{
    memset(a->list,0,N);
}

static inline void reset(bitset* a,int i)
{
    a->list[i>>6]&=~(1ULL<<(i&63));
}

static inline void set_all(bitset* a)
{
    memset(a->list,-1,N);
}

static inline void set(bitset* a,int i)
{
    a->list[i>>6]|=1ULL<<(i&63);
}

static inline bool test(const bitset* a,int i)
{
    return (a->list[i>>6]&(1ULL<<(i&63)))!=0;
}

static inline int max(int a,int b)
{
    return a>b?a:b;
}

int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize)
{
    const int dir[4][2]={-1,0,0,-1,0,1,1,0};
    int m=heightMapSize;
    int n=heightMapColSize[0];
    heap* pq=initialize(16);
    bitset visited[m];
    for(int i=0;i<m;i++)
    {
        reset_all(&visited[i]);
    }
    for(int i=0;i<m;i++)
    {
        push_min(pq,(T){heightMap[i][0],i,0});
        push_min(pq,(T){heightMap[i][n-1],i,n-1});
        set(&visited[i],0);
        set(&visited[i],n-1);
    }
    for(int i=1;i<n-1;i++)
    {
        push_min(pq,(T){heightMap[0][i],0,i});
        push_min(pq,(T){heightMap[m-1][i],m-1,i});
        set(&visited[0],i);
        set(&visited[m-1],i);
    }
    int ans=0;
    while(!empty(pq))
    {
        T t=top(pq);
        pop_min(pq);
        for(int d=0;d<4;d++)
        {
            int nx=t.x+dir[d][0];
            int ny=t.y+dir[d][1];
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&!test(&visited[nx],ny))
            {
                ans+=max(0,t.h-heightMap[nx][ny]);
                push_min(pq,(T){max(t.h,heightMap[nx][ny]),nx,ny});
                set(&visited[nx],ny);
            }
        }
    }
    clear(pq);
    return ans;
}
