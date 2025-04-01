#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100083

typedef struct
{
    int id;
    int min;
    int count;
    struct node* next;
} node;

node* hashtable[MAX];

inline int hash_func(int x)
{
    return x%MAX;
}

int find(int x,int space)
{
    int hash=hash_func(x%space);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->id==x%space)
        {
            return 1;
        }
        temp=(node*)temp->next;
    }
    return 0;
}

node* create(int x,int space)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->id=x%space;
    newnode->min=x;
    newnode->count=1;
    newnode->next=NULL;
    return newnode;
}

void insert(int x,int space)
{
    int hash=hash_func(x%space);
    node* newnode=create(x,space);
    newnode->next=(struct node*)hashtable[hash];
    hashtable[hash]=newnode;
}

void update(int x,int space,int* min,int* max)
{
    int hash;
    node* temp;
    if(find(x,space))
    {
        hash=hash_func(x%space);
        temp=hashtable[hash];
        while(temp)
        {
            if(temp->id==x%space)
            {
                break;
            }
            temp=(node*)temp->next;
        }
        temp->count++;
        if(x<temp->min)
        {
            temp->min=x;
        }
        if(temp->count>*max)
        {
            *max=temp->count;
            *min=temp->min;
        }
        else if(temp->count==*max)
        {
            if(*min>temp->min)
            {
                *min=temp->min;
            }
        }
    }
    else
    {
        insert(x,space);
        if(*max==0)
        {
            *max=1;
            *min=x;
        }
        else if(*max==1&&*min>x)
        {
            *min=x;
        }
    }
}

void initialize(void)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        hashtable[i]=NULL;
    }
}

void clear(void)
{
    int i;
    node* temp;
    node* prev;
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

int destroyTargets(int* nums, int numsSize, int space)
{
    int i,min,max;
    min=INT_MAX;
    max=0;
    initialize();
    for(i=0;i<numsSize;i++)
    {
        update(nums[i],space,&min,&max);
    }
    clear();
    return min;
}
