#include <stdio.h>
#include <stdlib.h>
//hash table
#define M 10083

typedef struct hashnode
{
    int t;
    int p;
    struct hashnode* next;
} hashnode;

void initialize(hashnode*** list)
{
    int i;
    *list=(hashnode**)malloc(sizeof(hashnode*)*M);
    for(i=0;i<M;i++)
    {
        (*list)[i]=NULL;
    }
}

inline int hash_func(int t)
{
    return t%M;
}

hashnode* create_hashnode(int t,int p)
{
    hashnode* newnode=(hashnode*)malloc(sizeof(hashnode));
    newnode->t=t;
    newnode->p=p;
    newnode->next=NULL;
    return newnode;
}

hashnode* find(int t,hashnode** hashtable)
{
    int hash=hash_func(t);
    hashnode* temp=hashtable[hash];
    while(temp)
    {
        if(temp->t==t)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

void insert(int t,int p,hashnode** hashtable)
{
    int hash=hash_func(t);
    hashnode* newnode=create_hashnode(t,p);
    newnode->next=hashtable[hash];
    hashtable[hash]=newnode;
}

void clear(hashnode** hashtable)
{
    int i;
    hashnode* temp;
    hashnode* prev;
    for(i=0;i<M;i++)
    {
        temp=hashtable[i];
        while(temp)
        {
            prev=temp;
            temp=temp->next;
            free(prev);
        }
    }
    free(hashtable);
}
//heap
typedef struct
{
    int t;
    int p;
} pair;

struct heap
{
    pair* list;
    int size;
    int capacity;
};

inline long long maxi(long long a,long long b)
{
    return a>b?a:b;
}

inline long long mini(long long a,long long b)
{
    return a<b?a:b;
}

inline void swap(pair* a,pair* b)
{
    pair t=*a;
    *a=*b;
    *b=t;
}

struct heap* initialize_heap(int n)
{
    struct heap* h=(struct heap*)malloc(sizeof(struct heap));
    h->size=0;
    h->capacity=n;
    h->list=(pair*)malloc(sizeof(pair)*n);
    return h;
}

pair top(struct heap* heap)
{
    return heap->list[0];
}

void clear_heap(struct heap* h)
{
    free(h->list);
    free(h);
}
//minheap
void heapify_min(struct heap* minheap,int i)
{
    int smallest=i;
    int l,r;
    while(1)
    {
        l=2*i+1;
        r=2*i+2;
        if(l<minheap->size&&minheap->list[l].p<minheap->list[smallest].p)
        {
            smallest=l;
        }
        if(r<minheap->size&&minheap->list[r].p<minheap->list[smallest].p)
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

void push_min(struct heap* minheap,int t,int p)
{
    if(minheap->size>=minheap->capacity)
    {
        minheap->capacity*=2;
        minheap->list=(pair*)realloc(minheap->list,sizeof(pair)*minheap->capacity);
    }
    int i=minheap->size;
    minheap->size++;
    minheap->list[i]=(pair){t,p};
    while(i&&minheap->list[i].p<minheap->list[(i-1)/2].p)
    {
        swap(&minheap->list[i],&minheap->list[(i-1)/2]);
        i=(i-1)/2;
    }
}

void pop_min(struct heap* minheap)
{
    minheap->size--;
    minheap->list[0]=minheap->list[minheap->size];
    heapify_min(minheap,0);
}
//maxheap
void heapify_max(struct heap* maxheap,int i)
{
    int largest=i;
    int l,r;
    while(1)
    {
        l=2*i+1;
        r=2*i+2;
        if(l<maxheap->size&&maxheap->list[l].p>maxheap->list[largest].p)
        {
            largest=l;
        }
        if(r<maxheap->size&&maxheap->list[r].p>maxheap->list[largest].p)
        {
            largest=r;
        }
        if(i==largest)
        {
            break;
        }
        swap(&maxheap->list[i],&maxheap->list[largest]);
        i=largest;
    }
}

void push_max(struct heap* maxheap,int t,int p)
{
    if(maxheap->size>=maxheap->capacity)
    {
        maxheap->capacity*=2;
        maxheap->list=(pair*)realloc(maxheap->list,sizeof(pair)*maxheap->capacity);
    }
    int i=maxheap->size;
    maxheap->size++;
    maxheap->list[i]=(pair){t,p};
    while(i&&maxheap->list[i].p>maxheap->list[(i-1)/2].p)
    {
        swap(&maxheap->list[i],&maxheap->list[(i-1)/2]);
        i=(i-1)/2;
    }
}

void pop_max(struct heap* maxheap)
{
    maxheap->size--;
    maxheap->list[0]=maxheap->list[maxheap->size];
    heapify_max(maxheap,0);
}
//main class
typedef struct
{
    hashnode** hashtable;
    struct heap* minheap;
    struct heap* maxheap;
    int time;
} StockPrice;

StockPrice* stockPriceCreate(void)
{
    StockPrice* obj=(StockPrice*)malloc(sizeof(StockPrice));
    initialize(&obj->hashtable);
    obj->minheap=initialize_heap(10);
    obj->maxheap=initialize_heap(10);
    obj->time=0;
    return obj;
}

void stockPriceUpdate(StockPrice* obj, int t, int p)
{
    hashnode* temp=find(t,obj->hashtable);
    if(temp)
    {
        temp->p=p;
    }
    else
    {
        insert(t,p,obj->hashtable);
    }
    push_max(obj->maxheap,t,p);
    push_min(obj->minheap,t,p);
    if(t>obj->time)
    {
        obj->time=t;
    }
}

int stockPriceCurrent(StockPrice* obj)
{
    return find(obj->time,obj->hashtable)->p;
}

int stockPriceMaximum(StockPrice* obj)
{
    pair temp;
    while(1)
    {
        temp=top(obj->maxheap);
        if(temp.p!=find(temp.t,obj->hashtable)->p)
        {
            pop_max(obj->maxheap);
        }
        else
        {
            break;
        }
    }
    return top(obj->maxheap).p;
}

int stockPriceMinimum(StockPrice* obj)
{
    pair temp;
    while(1)
    {
        temp=top(obj->minheap);
        if(temp.p!=find(temp.t,obj->hashtable)->p)
        {
            pop_min(obj->minheap);
        }
        else
        {
            break;
        }
    }
    return top(obj->minheap).p;
}

void stockPriceFree(StockPrice* obj)
{
    clear(obj->hashtable);
    clear_heap(obj->maxheap);
    clear_heap(obj->minheap);
    free(obj);
}
