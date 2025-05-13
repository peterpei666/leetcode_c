#include <stdio.h>
#include <stdlib.h>

#define M 100083

typedef struct
{
    int m;
    int n;
    struct node* next;
}node;

node* hashtable[M];

void initialize(void)
{
    int i;
    for(i=0;i<M;i++)
    {
        hashtable[i]=NULL;
    }
}

inline int hash_func(int m)
{
    return m%M;
}

node* create(int m)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->m=m;
    newnode->n=1;
    newnode->next=NULL;
    return newnode;
}

node* find(int m)
{
    int hash=hash_func(m);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->m==m)
        {
            return temp;
        }
        temp=(node*)temp->next;
    }
    return NULL;
}

void insert(int m)
{
    int hash=hash_func(m);
    node* newnode=create(m);
    newnode->next=(struct node*)hashtable[hash];
    hashtable[hash]=newnode;
}

void clear(void)
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

inline int maxi(int a,int b)
{
    return a>b?a:b;
}

int minLengthAfterRemovals(int* nums, int n)
{
    int i,m=0;
    node* temp;
    initialize();
    for(i=0;i<n;i++)
    {
        temp=find(nums[i]);
        if(temp)
        {
            temp->n++;
            m=maxi(temp->n,m);
        }
        else
        {
            insert(nums[i]);
            m=maxi(1,m);
        }
    }
    clear();
    if(m<=n/2)
    {
        return n%2;
    }
    else
    {
        return 2*m-n;
    }
}
