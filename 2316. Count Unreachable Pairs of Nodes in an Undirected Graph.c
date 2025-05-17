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
    return m*97%M;
}

node* create(int m)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->m=m;
    newnode->n=1;
    newnode->next=NULL;
    return newnode;
}

node* search(int m)
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

int find(int parent[],int x)
{
    if(parent[x]==x)
    {
        return x;
    }
    parent[x]=find(parent,parent[x]);
    return parent[x];
}

void unite(int parent[],int x,int y)
{
    int p1=find(parent,x);
    int p2=find(parent,y);
    if(p1<p2)
    {
        parent[p2]=p1;
    }
    else if(p1>p2)
    {
        parent[p1]=p2;
    }
}

long long countPairs(int n, int** edges, int m, int* edgesColSize)
{
    int i,p;
    int parent[n];
    long long ret=0;
    node* temp;
    for(i=0;i<n;i++)
    {
        parent[i]=i;
    }
    for(i=0;i<m;i++)
    {
        unite(parent,edges[i][0],edges[i][1]);
    }
    initialize();
    for(i=0;i<n;i++)
    {
        p=find(parent,i);
        temp=search(p);
        if(temp)
        {
            temp->n++;
        }
        else
        {
            insert(p);
        }
    }
    for(i=0;i<M;i++)
    {
        temp=hashtable[i];
        while(temp)
        {
            ret+=(long long)temp->n*(long long)(n-temp->n);
            temp=(node*)temp->next;
        }
    }
    clear();
    return ret/2;
}
