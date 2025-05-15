#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define M 100083

typedef struct
{
    int n;
    int idx;
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

node* create(int n,int idx)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->n=n;
    newnode->idx=idx;
    newnode->next=NULL;
    return newnode;
}

node* find(int n)
{
    int hash=hash_func(n);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->n==n)
        {
            return temp;
        }
        temp=(node*)temp->next;
    }
    return NULL;
}

void insert(int n,int idx)
{
    int hash=hash_func(n);
    node* newnode=create(n,idx);
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

inline int mini(int a,int b)
{
    return a<b?a:b;
}

int* assignElements(int* groups, int m, int* elements, int n, int* returnSize)
{
    int i,j;
    double big;
    node* temp;
    int* ret=(int*)malloc(sizeof(int)*m);
    for(i=0;i<m;i++)
    {
        ret[i]=INT_MAX;
    }
    initialize();
    for(i=0;i<n;i++)
    {
        if(find(elements[i])==NULL)
        {
            insert(elements[i],i);
        }
    }
    for(i=0;i<m;i++)
    {
        big=sqrt(groups[i]);
        for(int j=1;j<=big;j++)
        {
            if(groups[i]%j==0)
            {
                temp=find(j);
                if(temp)
                {
                    ret[i]=mini(ret[i],temp->idx);
                }
                temp=find(groups[i]/j);
                if(temp)
                {
                    ret[i]=mini(ret[i],temp->idx);
                }
            }
        }
        if(ret[i]==INT_MAX)
        {
            ret[i]=-1;
        }
    }
    *returnSize=m;
    return ret;
}
