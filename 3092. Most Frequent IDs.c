#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//maxheap
struct pair
{
    int id;
    long long freq;
};

struct heap
{
    struct pair* list;
    int size;
    int capacity;
};

struct heap* initialize_maxheap(void)
{
    struct heap* h=(struct heap*)malloc(sizeof(struct heap));
    h->size=0;
    h->capacity=100;
    h->list=(struct pair*)malloc(sizeof(struct pair)*100);
    return h;
}

inline void swap(struct pair* a,struct pair* b)
{
    struct pair t=*a;
    *a=*b;
    *b=t;
}

void heapify_max(struct heap* maxheap,int i)
{
    int largest=i;
    int l,r;
    while(1)
    {
        l=2*i+1;
        r=2*i+2;
        if(l<maxheap->size&&maxheap->list[l].freq>maxheap->list[largest].freq)
        {
            largest=l;
        }
        if(r<maxheap->size&&maxheap->list[r].freq>maxheap->list[largest].freq)
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

void insert_maxheap(struct heap* maxheap,struct pair n)
{
    if(maxheap->size>=maxheap->capacity)
    {
        maxheap->capacity*=2;
        maxheap->list=(struct pair*)realloc(maxheap->list,sizeof(struct pair)*maxheap->capacity);
    }
    int i=maxheap->size;
    maxheap->size++;
    maxheap->list[i]=n;
    while(i&&maxheap->list[i].freq>maxheap->list[(i-1)/2].freq)
    {
        swap(&maxheap->list[i],&maxheap->list[(i-1)/2]);
        i=(i-1)/2;
    }
}

void pop(struct heap* maxheap)
{
    maxheap->size--;
    maxheap->list[0]=maxheap->list[maxheap->size];
    heapify_max(maxheap,0);
}

struct pair top(struct heap* maxheap)
 {
     return maxheap->list[0];
 }
 
void clear_maxheap(struct heap* h)
{
    free(h->list);
    free(h);
}
//hash table
#define M 100083

typedef struct
{
    int id;
    long long freq;
    struct node* next;
}node;

node* hashtable[M];

void initialize_hashtable(void)
{
    int i;
    for(i=0;i<M;i++)
    {
        hashtable[i]=NULL;
    }
}

inline int hash_func(int m)
{
    return m*97%M;
}

node* create(int id,long long freq)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->id=id;
    newnode->freq=freq;
    newnode->next=NULL;
    return newnode;
}

node* find(int id)
{
    int hash=hash_func(id);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->id==id)
        {
            return temp;
        }
        temp=(node*)temp->next;
    }
    return NULL;
}

void insert(int id,long long freq)
{
    int hash=hash_func(id);
    node* newnode=create(id,freq);
    newnode->next=(struct node*)hashtable[hash];
    hashtable[hash]=newnode;
}

void clear_hashtable(void)
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
            temp=(node*)temp->next;
            free(prev);
        }
    }
}

long long* mostFrequentIDs(int* nums, int n, int* freq, int freqSize, int* returnSize)
{
    int i;
    node* temp;
    struct pair t;
    struct heap* maxheap=initialize_maxheap();
    initialize_hashtable();
    long long* ret=(long long*)malloc(sizeof(long long)*n);
    for(i=0;i<n;i++)
    {
        temp=find(nums[i]);
        if(temp)
        {
            temp->freq+=freq[i];
            insert_maxheap(maxheap,(struct pair){nums[i],temp->freq});
        }
        else
        {
            insert(nums[i],(long long)freq[i]);
            insert_maxheap(maxheap,(struct pair){nums[i],freq[i]});
        }
        while(maxheap->size)
        {
            t=top(maxheap);
            temp=find(t.id);
            if(temp->freq==t.freq)
            {
                break;
            }
            pop(maxheap);
        }
        t=top(maxheap);
        ret[i]=t.freq;
    }
    *returnSize=n;
    return ret;
}
