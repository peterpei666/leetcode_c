#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define M 10083

typedef struct node
{
    int m;
    int n;
    struct node* next;
} node;

node* hashtable[M];

static inline void initialize(void)
{
    memset(hashtable,0,sizeof(hashtable));
}

static inline int hash_func(int m)
{
    return (m%M+M)*97%M;
}

static inline node* create(int m,int n)
{
     node* newnode=(node*)malloc(sizeof(node));
     newnode->m=m;
     newnode->n=n;
     newnode->next=NULL;
     return newnode;
}

static inline node* find(int m)
{
    int hash=hash_func(m);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->m==m)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

static inline void insert(int m,int n)
{
    int hash=hash_func(m);
    node* newnode=create(m,n);
    newnode->next=hashtable[hash];
    hashtable[hash]=newnode;
}

static inline void clear(void)
{
    int i;
    node* temp;
    node* prev;
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
}

static inline void erase(int m)
{
    node* temp=hashtable[hash_func(m)];
    node* prev=NULL;
    while(temp&&temp->m!=m)
    {
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL) hashtable[hash_func(m)]=temp->next;
    else prev->next=temp->next;
    free(temp);
}
//heap
typedef struct
{
    int* list;
    int size;
    int capacity;
} heap;
 
heap* initialize_heap(int n)
{
    heap* h=(heap*)malloc(sizeof(heap));
    h->size=0;
    h->capacity=n;
    h->list=(int*)malloc(sizeof(int)*n);
    return h;
}
 
static inline void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

static inline int top_heap(heap* h)
{
    return h->list[0];
}
 
static inline void clear_heap(heap* h)
{
    free(h->list);
    free(h);
}

static inline bool empty_heap(heap* h)
{
    return h->size==0;
}
//maxheap
void heapify_max(heap* maxheap,int i)
{
    int largest=i;
    int l,r;
    while(1)
    {
        l=2*i+1;
        r=2*i+2;
        if(l<maxheap->size&&maxheap->list[l]>maxheap->list[largest])
        {
            largest=l;
        }
        if(r<maxheap->size&&maxheap->list[r]>maxheap->list[largest])
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

void push_max(heap* maxheap,int n)
{
    if(maxheap->size>=maxheap->capacity)
    {
        maxheap->capacity*=2;
        maxheap->list=(int*)realloc(maxheap->list,sizeof(int)*maxheap->capacity);
    }
    int i=maxheap->size;
    maxheap->size++;
    maxheap->list[i]=n;
    while(i&&maxheap->list[i]>maxheap->list[(i-1)/2])
    {
        swap(&maxheap->list[i],&maxheap->list[(i-1)/2]);
        i=(i-1)/2;
    }
}
 
static inline void pop_max(heap* maxheap)
{
    maxheap->size--;
    maxheap->list[0]=maxheap->list[maxheap->size];
    heapify_max(maxheap,0);
}
//minheap
void heapify_min(heap* minheap,int i)
{
    int smallest=i;
    int l,r;
    while(1)
    {
        l=2*i+1;
        r=2*i+2;
        if(l<minheap->size&&minheap->list[l]<minheap->list[smallest])
        {
            smallest=l;
        }
        if(r<minheap->size&&minheap->list[r]<minheap->list[smallest])
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

void push_min(heap* minheap,int n)
{
    if(minheap->size>=minheap->capacity)
    {
        minheap->capacity*=2;
        minheap->list=(int*)realloc(minheap->list,sizeof(int)*minheap->capacity);
    }
    int i=minheap->size;
    minheap->size++;
    minheap->list[i]=n;
    while(i&&minheap->list[i]<minheap->list[(i-1)/2])
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

void prune_maxheap(heap* maxheap)
{
    while(!empty_heap(maxheap))
    {
        int temp=top_heap(maxheap);
        node* t=find(temp);
        if(t)
        {
            pop_max(maxheap);
            t->n--;
            if(t->n==0)
            {
                erase(temp);
            }
        }
        else
        {
            break;
        }
    }
}

void prune_minheap(heap* minheap)
{
    while(!empty_heap(minheap))
    {
        int temp=top_heap(minheap);
        node* t=find(temp);
        if(t)
        {
            pop_min(minheap);
            t->n--;
            if(t->n==0)
            {
                erase(temp);
            }
        }
        else
        {
            break;
        }
    }
}

void rebalance(heap* maxheap,heap* minheap,int* max_sz,int* min_sz)
{
    if(*max_sz>*min_sz+1)
    {
        push_min(minheap,top_heap(maxheap));
        pop_max(maxheap);
        (*max_sz)--;
        (*min_sz)++;
        prune_maxheap(maxheap);
    }
    else if(*min_sz>*max_sz)
    {
        push_max(maxheap,top_heap(minheap));
        pop_min(minheap);
        (*min_sz)--;
        (*max_sz)++;
        prune_minheap(minheap);
    }
}

double* medianSlidingWindow(int* nums, int n, int k, int* returnSize)
{
    heap* maxheap=initialize_heap(n/2+1);
    heap* minheap=initialize_heap(n/2+1);
    initialize();
    int max_sz=0,min_sz=0;
    for(int i=0;i<k;i++)
    {
        if(empty_heap(maxheap)||nums[i]<=top_heap(maxheap))
        {
            push_max(maxheap,nums[i]);
            max_sz++;
        }
        else
        {
            push_min(minheap,nums[i]);
            min_sz++;
        }
        rebalance(maxheap,minheap,&max_sz,&min_sz);
    }
    double* ans=(double*)malloc(sizeof(double)*(n-k+1));
    if(k%2)
    {
        ans[0]=top_heap(maxheap);
    }
    else
    {
        ans[0]=top_heap(maxheap)/2.0+top_heap(minheap)/2.0;
    }
    for(int i=k;i<n;i++)
    {
        if(!empty_heap(maxheap)&&nums[i]<=top_heap(maxheap))
        {
            push_max(maxheap,nums[i]);
            max_sz++;
        }
        else
        {
            push_min(minheap,nums[i]);
            min_sz++;
        }
        node* temp=find(nums[i-k]);
        if(temp)
        {
            temp->n++;
        }
        else
        {
            insert(nums[i-k],1);
        }
        if(nums[i-k]<=top_heap(maxheap))
        {
            max_sz--;
            if(nums[i-k]==top_heap(maxheap))
            {
                prune_maxheap(maxheap);
            }
        }
        else
        {
            min_sz--;
            if(!empty_heap(minheap)&&nums[i-k]==top_heap(minheap))
            {
                prune_minheap(minheap);
            }
        }
        rebalance(maxheap,minheap,&max_sz,&min_sz);
        if(k%2)
        {
            ans[i-k+1]=top_heap(maxheap);
        }
        else
        {
            ans[i-k+1]=top_heap(maxheap)/2.0+top_heap(minheap)/2.0;
        }
    }
    clear();
    clear_heap(maxheap);
    clear_heap(minheap);
    *returnSize=n-k+1;
    return ans;
}
