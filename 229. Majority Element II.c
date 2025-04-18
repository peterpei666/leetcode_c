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

inline int hash_func(int id)
{
    return (id%MAX+MAX)%MAX;
}

void initialize(void)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        hashtable[i]=NULL;
    }
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
    node* newnode=(node*)malloc(sizeof(node));
    newnode->id=id;
    newnode->count=1;
    int hash=hash_func(id);
    newnode->next=(struct node*)hashtable[hash];
    hashtable[hash]=newnode;
}

void update(int id)
{
    node* temp=find(id);
    if(temp)
    {
        temp->count++;
    }
    else
    {
        insert(id);
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

int* majorityElement(int* nums, int numsSize, int* returnSize)
{
    int i,capacity=2,m=0;
    int* ret=(int*)malloc(sizeof(int)*capacity);
    node* temp;
    initialize();
    for(i=0;i<numsSize;i++)
    {
        update(nums[i]);
    }
    for(i=0;i<MAX;i++)
    {
        temp=hashtable[i];
        while(temp)
        {
            if(temp->count>numsSize/3)
            {
                ret[m]=temp->id;
                m++;
                if(m>=capacity-2)
                {
                    capacity*=2;
                    ret=realloc(ret,sizeof(int)*capacity);
                }
            }
            temp=(node*)temp->next;
        }
    }
    clear();
    *returnSize=m;
    return ret;
}
