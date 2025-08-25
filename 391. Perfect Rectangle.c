#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define M 200083

typedef struct node
{
    long long m;
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

static inline int hash_func(long long m)
{
    return (m%M+M)*97%M;
}

static inline node* create(long long m,int n)
{
     node* newnode=(node*)malloc(sizeof(node));
     newnode->m=m;
     newnode->n=n;
     newnode->next=NULL;
     return newnode;
}

static inline node* find(long long m)
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

static inline void insert(long long m,int n)
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

bool isRectangleCover(int** rectangles, int n, int* rectanglesColSize)
{
    const long long N=1e6;
    initialize();
    for(int i=0;i<n;i++)
    {
        node* temp;
        temp=find(rectangles[i][0]*N+rectangles[i][1]);
        if(temp)
        {
            temp->n++;
        }
        else
        {
            insert(rectangles[i][0]*N+rectangles[i][1],1);
        }
        temp=find(rectangles[i][0]*N+rectangles[i][3]);
        if(temp)
        {
            temp->n--;
        }
        else
        {
            insert(rectangles[i][0]*N+rectangles[i][3],-1);
        }
        temp=find(rectangles[i][2]*N+rectangles[i][1]);
        if(temp)
        {
            temp->n--;
        }
        else
        {
            insert(rectangles[i][2]*N+rectangles[i][1],-1);
        }
        temp=find(rectangles[i][2]*N+rectangles[i][3]);
        if(temp)
        {
            temp->n++;
        }
        else
        {
            insert(rectangles[i][2]*N+rectangles[i][3],1);
        }
    }
    int cnt=0;
    for(int i=0;i<M;i++)
    {
        node* temp=hashtable[i];
        while(temp)
        {
            if(temp->n!=0)
            {
                if(abs(temp->n)!=1)
                {
                    clear();
                    return false;
                }
                cnt++;
            }
            temp=temp->next;
        }
    }
    clear();
    return cnt==4;
}
