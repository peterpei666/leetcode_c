#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define M 10083

typedef struct
{
    int a;
    int b;
} pair;

typedef struct node
{
    pair m;
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

static inline int hash_func(int a,int b)
{
    return (a^(b<<1))%M*97%M;
}

static inline node* create(int a,int b,int n)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->m=(pair){a,b};
    newnode->n=n;
    newnode->next=NULL;
    return newnode;
}

static inline node* find(int a,int b)
{
    int hash=hash_func(a,b);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->m.a==a&&temp->m.b==b)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

static inline void insert(int a,int b,int n)
{
    int hash=hash_func(a,b);
    node* newnode=create(a,b,n);
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

static inline int min(int a,int b)
{
    return a<b?a:b;
}

static inline int cost(char* s,int i,int j)
{
    int c=0;
    for(;i<j;i++,j--) if(s[i]!=s[j]) c++;
    return c;
}

int dfs(char* s,int n,int i,int k)
{
    node* temp=find(i,k);
    if(temp)
    {
        return temp->n;
    }
    if(n-i==k)
    {
        return 0;
    }
    if(k==1)
    {
        return cost(s,i,n-1);
    }
    int res=INT_MAX;
    for(int j=i+1;j<n-k+2;j++)
    {
        res=min(res,dfs(s,n,j,k-1)+cost(s,i,j-1));
    }
    insert(i,k,res);
    return res;
}

int palindromePartition(char* s, int k)
{
    initialize();
    int n=(int)strlen(s);
    int ans=dfs(s,n,0,k);
    clear();
    return ans;
}
