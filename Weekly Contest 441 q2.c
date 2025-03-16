#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int p;
    int f;
    struct node* prev;
    struct node* next;
} node;

node* hashtable[100001]={NULL};

node* create(int id,int p)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->id=id;
    newnode->p=p;
    newnode->f=0;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

void insert(int id,int p)
{
    node* newnode=create(id,p);
    node* temp;
    if(hashtable[id]==NULL)
    {
        hashtable[id]=newnode;
    }
    else
    {
        newnode->next=(struct node*)hashtable[id];
        hashtable[id]->prev=(struct node*)newnode;
        hashtable[id]=newnode;
    }
}

void ring(void)
{
    int i;
    node* temp;
    for(i=0;i<100001;i++)
    {
        if(hashtable[i])
        {
            temp=hashtable[i];
            while(temp->next)
            {
                temp=(node*)temp->next;
            }
            temp->f=1;
            temp->next=(struct node*)hashtable[i];
            hashtable[i]->prev=(struct node*)temp;
        }
    }
}

int search(int id,int p,int size)
{
    node* temp=hashtable[id];
    node* prev;
    node* next;
    int dis1,dis2;
    while(temp->p!=p)
    {
        temp=(node*)temp->next;
    }
    if(((node*)(temp->next))->p==p)
    {
        return -1;
    }
    else
    {
        next=(node*)temp->next;
        prev=(node*)temp->prev;
        if(next->p>p)
        {
            dis1=next->p-p;
        }
        else
        {
            dis1=p-next->p;
        }
        dis1=(dis1>size-dis1)?size-dis1:dis1;
        if(prev->p>p)
        {
            dis2=prev->p-p;
        }
        else
        {
            dis2=p-prev->p;
        }
        dis2=(dis2>size-dis2)?size-dis2:dis2;
        return (dis1>dis2)?dis2:dis1;
    }
}

void clear(void)
{
    int i;
    node* temp;
    node* prev;
    for(i=0;i<100001;i++)
    {
        if(hashtable[i])
        {
            temp=hashtable[i];
            while(temp->f==0)
            {
                prev=temp;
                temp=(node*)temp->next;
                free(prev);
            }
            free(temp);
            hashtable[i]=NULL;
        }
    }
}

int* solveQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize)
{
    if(queriesSize==0)
    {
        *returnSize=0;
        return NULL;
    }
    int i;
    *returnSize=queriesSize;
    int* list=(int*)malloc(queriesSize*sizeof(int));
    for(i=0;i<numsSize;i++)
    {
        insert(nums[i],i);
    }
    ring();
    for(i=0;i<queriesSize;i++)
    {
        list[i]=search(nums[queries[i]],queries[i],numsSize);
    }
    clear();
    return list;
}
