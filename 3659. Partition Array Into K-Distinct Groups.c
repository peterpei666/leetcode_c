#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define M 100083

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

bool partitionArray(int* nums, int n, int k)
{
    if (n % k)
    {
        return false;
    }
    initialize();
    for (int i = 0; i < n; i++)
    {
        node* temp = find(nums[i]);
        if (temp)
        {
            temp->n++;
        }
        else
        {
            insert(nums[i], 1);
        }
    }
    for (int i = 0; i < M; i++)
    {
        node* temp = hashtable[i];
        while (temp)
        {
            if (temp->n > n / k)
            {
                return false;
            }
            temp = temp-> next;
        }
    }
    clear();
    return true;
}
