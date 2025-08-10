#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define M 200083

typedef struct
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
    
static inline bool count(int m)
{
    int hash=hash_func(m);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->m==m)
        {
            return true;
        }
        temp=(node*)temp->next;
    }
    return false;
}
    
static inline void insert(int m)
{
    int hash=hash_func(m);
    node* newnode=create(m);
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

bool containsDuplicate(int* nums, int n)
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
    }
    return false;
}
