#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 100083

typedef struct node
{
    long long m;
    long long n;
    struct node* next;
} node;

node* hashtable[M];
int count;

static inline void initialize(void)
{
    int i;
    count=0;
    memset(hashtable,0,sizeof(hashtable));
}

static inline int hash_func(long long m)
{
    return m*97%M;
}

static inline node* create(long long m,long long n)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->m=m;
    newnode->n=n;
    newnode->next=NULL;
    return newnode;
}

static inline node* find(long long m)
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

static inline void insert(long long m,long long n)
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

long long taskSchedulerII(int* tasks, int n, int space)
{
    initialize();
    long long cur=0;
    for(int i=0;i<n;i++)
    {
        node* temp=find(tasks[i]);
        if(temp)
        {
            if(cur<temp->n)
            {
                cur=temp->n;
            }
            cur++;
            temp->n=cur+space;
        }
        else
        {
            cur++;
            insert(tasks[i],cur+space);
        }
    }
    clear();
    return cur;
}
