#include <stdio.h>
#include <stdlib.h>

#define MAX 100083

typedef struct
{
    int id;
    int count;
    struct node* next;
} node;

node* hashtable[MAX];

void initialize(void)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        hashtable[i]=NULL;
    }
}

int hash_func(int x)
{
    return x%MAX;
}

node* create(int id)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->id=id;
    newnode->count=1;
    newnode->next=NULL;
    return newnode;
}

node* find(int id)
{
    int hash=hash_func(id);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->id==id)
        {
            return temp;
        }
        temp=(node*)temp->next;
    }
    return NULL;
}

void insert(int id)
{
    node* temp=find(id);
    if(temp)
    {
        temp->count++;
    }
    else
    {
        int hash=hash_func(id);
        temp=create(id);
        temp->next=(struct node*)hashtable[hash];
        hashtable[hash]=temp;
    }
}

void clear(void)
{
    int i;
    node* prev;
    node* temp;
    for(i=0;i<MAX;i++)
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

int tupleSameProduct(int* nums, int numsSize)
{
    int i,j,count=0;
    node* temp;
    initialize();
    for(i=0;i<numsSize-1;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            insert(nums[i]*nums[j]);
        }
    }
    for(i=0;i<MAX;i++)
    {
        temp=hashtable[i];
        while(temp)
        {
            count+=4*(temp->count)*(temp->count-1);
            temp=(node*)temp->next;
        }
    }
    clear();
    return count;
}
