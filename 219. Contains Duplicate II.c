#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define M 200083

typedef struct node
{
    int m;
    struct node* next;
} node;
    
node* hashtable[M];
    
static inline void initialize(void)
{
    int i;
    memset(hashtable,0,sizeof(hashtable));
}
    
static inline int hash_func(int m)
{
    return (m%M+M)*97%M;
}
    
static inline node* create(int m)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->m=m;
    newnode->next=NULL;
    return newnode;
}

void erase(int m)
{
    int hash=hash_func(m);
    node* prev=NULL;
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->m==m)
        {
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    if(!temp) return;
    if(prev)
    {
        prev->next=temp->next;
        free(temp);
    }
    else
    {
        hashtable[hash]=temp->next;
        free(temp);
    }
}

static inline bool count(int m)
{
    int hash=hash_func(m);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->m==m) return true;
        temp=temp->next;
    }
    return false;
}
    
static inline void insert(int m)
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

bool containsNearbyDuplicate(int* nums, int n, int k)
{
    initialize();
    for(int i=0;i<n;i++)
    {
        if(count(nums[i]))
        {
            clear();
            return true;
        }
        insert(nums[i]);
        if(i-k>=0)
        {
            erase(nums[i-k]);
        }
    }
    clear();
    return false;
}
