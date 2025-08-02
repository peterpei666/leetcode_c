#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define M 10083

typedef struct node
{
    int m;
    int n;
    struct node* next;
} node;

node* hashtable[M];
int count;

static inline void initialize(void)
{
    count=0;
    memset(hashtable,0,sizeof(hashtable));
}

static inline int hash_func(int m)
{
    return m*97%M;
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

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

static inline int min(int a,int b)
{
    return a<b?a:b;
}

long long minCost(int* basket1, int n, int* basket2, int basket2Size)
{
    initialize();
    int m=INT_MAX;
    for(int i=0;i<n;i++)
    {
        m=min(m,basket1[i]);
        node* temp=find(basket1[i]);
        if(temp)
        {
            temp->n++;
        }
        else
        {
            insert(basket1[i],1);
        }
    }
    for(int i=0;i<n;i++)
    {
        m=min(m,basket2[i]);
        node* temp=find(basket2[i]);
        if(temp)
        {
            temp->n--;
        }
        else
        {
            insert(basket2[i],-1);
        }
    }
    int* merge=(int*)malloc(sizeof(int)*10);
    int k=0;
    int capacity=10;
    for(int i=0;i<M;i++)
    {
        node* temp=hashtable[i];
        while(temp)
        {
            if(temp->n%2)
            {
                clear();
                free(merge);
                return -1;
            }
            for(int j=0;j<abs(temp->n)/2;j++)
            {
                if(k==capacity)
                {
                    capacity*=2;
                    merge=(int*)realloc(merge,sizeof(int)*capacity);
                }
                merge[k]=temp->m;
                k++;
            }
            temp=temp->next;
        }
    }
    if(k==0)
    {
        clear();
        free(merge);
        return 0;
    }
    qsort(merge,k,sizeof(int),cmp);
    long long ans=0;
    for(int i=0;i<k/2;i++)
    {
        ans+=min(2*m,merge[i]);
    }
    return ans;
}
