#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 10083

typedef struct node
{
    int m;
    int n;
    struct node* next;
} node;

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
        temp=temp->next;
    }
    return NULL;
}

void insert(int m)
{
    int hash=hash_func(m);
    node* newnode=create(m);
    newnode->next=hashtable[hash];
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
            temp=temp->next;
            free(prev);
        }
    }
}

int cmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

int* findOriginalArray(int* changed, int n, int* returnSize)
{
    if(n%2)
    {
        *returnSize=0;
        return NULL;
    }
    int i,j,k;
    node* temp;
    node* next;
    int* ret=(int*)malloc(sizeof(int)*n);
    initialize();
    qsort(changed,n,sizeof(int),cmp);
    for(i=0;i<n;i++)
    {
        temp=find(changed[i]);
        if(temp)
        {
            temp->n++;
        }
        else
        {
            insert(changed[i]);
        }
    }
    k=0;
    for(i=0;i<n;i++)
    {
        temp=find(changed[i]);
        if(temp->n==0)
        {
            continue;
        }
        next=find(2*changed[i]);
        if(next==NULL||next->n==0)
        {
            *returnSize=0;
            return NULL;
        }
        ret[k]=changed[i];
        k++;
        temp->n--;
        next->n--;
    }
    *returnSize=k;
    return ret;
}
