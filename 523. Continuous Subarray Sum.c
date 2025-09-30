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

void initialize(void)
{
    int i;
    count=0;
    memset(hashtable,0,sizeof(hashtable));
}

inline int hash_func(int m)
{
    return m%M;
}

node* create(int m,int n)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->m=m;
    newnode->n=n;
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

void insert(int m,int n)
{
    int hash=hash_func(m);
    node* newnode=create(m,n);
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
bool checkSubarraySum(int* nums, int n, int k)
{
    if(n<2)
    {
        return false;
    }
    initialize();
    insert(0,-1);
    int i,cur;
    node* temp;
    for(i=0,cur=0;i<n;i++)
    {
        cur+=nums[i];
        cur%=k;
        temp=find(cur);
        if(temp==NULL)
        {
            insert(cur,i);
        }
        else if(temp->n<=i-2)
        {
            clear();
            return true;
        }
    }
    clear();
    return false;
}
