#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    return m%M*97%M;
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

inline int min(int a,int b)
{
    return a<b?a:b;
}

int minSubarray(int* nums, int n, int p)
{
    int sum=0,cur=0;
    int i,target,ans=n;
    node* temp;
    for(i=0;i<n;i++)
    {
        sum=(sum+nums[i])%p;
    }
    if(sum==0)
    {
        return 0;
    }
    initialize();
    insert(0,-1);
    for(i=0;i<n;i++)
    {
        cur=(cur+nums[i])%p;
        target=(cur-sum+p)%p;
        temp=find(target);
        if(temp)
        {
            ans=min(ans,i-temp->n);
        }
        temp=find(cur);
        if(temp)
        {
            temp->n=i;
        }
        else
        {
            insert(cur,i);
        }
    }
    clear();
    return ans==n?-1:ans;
}
