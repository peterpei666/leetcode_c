#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define M 200083

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
    return (m%M)*97%M;
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

static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int rev(int x)
{
    int ans = 0;
    while (x)
    {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

int minMirrorPairDistance(int* nums, int n)
{
    int ans = INT_MAX;
    initialize();
    for (int i = 0; i < n; i++)
    {
        node* temp = find(nums[i]);
        if (temp)
        {
            ans = min(ans, i - temp->n);
        }
        int r = rev(nums[i]);
        temp = find(r);
        if (temp)
        {
            temp->n = i;
        }
        else
        {
            insert(r, i);
        }
    }
    clear();
    return ans == INT_MAX ? -1 : ans;
}
