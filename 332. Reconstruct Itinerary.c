#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define M 683
    
typedef struct node
{
    char* s;
    char** list;
    int sz;
    int idx;
    int capacity;
    struct node* next;
} node;
    
node* hashtable[M];
    
static inline void initialize(void)
{
    int i;
    memset(hashtable,0,sizeof(hashtable));
}
    
static inline int hash_func(char* s)
{
    int hash=0,i=0;
    while(s[i]!='\0') hash=(hash*97+s[i++])%M;
    return hash;
}
    
static inline node* create(char* s)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->s=s;
    newnode->sz=0;
    newnode->idx=0;
    newnode->capacity=8;
    newnode->list=(char**)malloc(sizeof(char*)*8);
    newnode->next=NULL;
    return newnode;
}
    
static inline node* find(char* s)
{
    int hash=hash_func(s);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(strcmp(temp->s,s)==0)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
    
static inline node* insert(char* s)
{
    int hash=hash_func(s);
    node* newnode=create(s);
    newnode->next=hashtable[hash];
    hashtable[hash]=newnode;
    return newnode;
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
    return strcmp(*((char**)p1),*((char**)p2));
}

void dfs(char* cur,char** ans,int* sz)
{
    node* temp=find(cur);
    while(temp&&temp->idx<temp->sz)
    {
        temp->idx++;
        dfs(temp->list[temp->idx-1],ans,sz);
    }
    ans[*sz]=cur;
    (*sz)++;
}

static inline void swap(char** a,char** b)
{
    char* temp=*a;
    *a=*b;
    *b=temp;
}

char** findItinerary(char*** tickets, int n, int* ticketsColSize, int* returnSize)
{
    initialize();
    for(int i=0;i<n;i++)
    {
        node* temp=find(tickets[i][0]);
        if(!temp)
        {
            temp=insert(tickets[i][0]);
        }
        if(temp->sz==temp->capacity)
        {
            temp->capacity*=2;
            temp->list=(char**)realloc(temp->list,sizeof(char*)*temp->capacity);
        }
        temp->list[temp->sz]=tickets[i][1];
        temp->sz++;
    }
    for(int i=0;i<M;i++)
    {
        node* temp=hashtable[i];
        while(temp)
        {
            qsort(temp->list,temp->sz,sizeof(char*),cmp);
            temp=temp->next;
        }
    }
    char** ans=(char**)malloc(sizeof(char*)*(n+1));
    int sz=0;
    dfs("JFK",ans,&sz);
    *returnSize=sz;
    clear();
    int l=0,r=sz-1;
    while(l<r)
    {
        swap(&ans[l],&ans[r]);
        l++;
        r--;
    }
    return ans;
}
