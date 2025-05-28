#include <stdio.h>
#include <stdlib.h>

#define M 100083

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

int countPairs(int* deliciousness, int n)
{
    const int mod=1e9+7;
    int i,j;
    long long cnt=0;
    int sum[22];
    node* temp;
    node* pair;
    sum[0]=1;
    for(i=1;i<22;i++)
    {
        sum[i]=sum[i-1]*2;
    }
    initialize();
    for(i=0;i<n;i++)
    {
        temp=find(deliciousness[i]);
        if(temp)
        {
            temp->n++;
        }
        else
        {
            insert(deliciousness[i]);
        }
    }
    for(i=0;i<M;i++)
    {
        temp=hashtable[i];
        while(temp)
        {
            for(j=0;j<22;j++)
            {
                if(sum[j]<2*temp->m)
                {
                    continue;
                }
                if(sum[j]==2*temp->m)
                {
                    cnt+=(long long)temp->n*(temp->n-1)/2;
                    cnt%=mod;
                }
                else
                {
                    pair=find(sum[j]-temp->m);
                    if(pair)
                    {
                        cnt+=(long long)temp->n*pair->n;
                        cnt%=mod;
                    }
                }
            }
            temp=temp->next;
        }
    }
    clear();
    return (int)cnt;
}
