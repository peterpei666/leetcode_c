#include <stdio.h>
#include <stdlib.h>

#define MAX 10083

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

inline int hash_func(int id)
{
    return id%MAX*97%MAX;
}

node* create(int id)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->id=id;
    newnode->count=1;
    newnode->next=NULL;
    return newnode;
}

void insert(int id)
{
    node* newnode=create(id);
    int hash=hash_func(id);
    newnode->next=(struct node*)hashtable[hash];
    hashtable[hash]=newnode;
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

void update(int id,long long* same)
{
    node* temp=find(id);
    if(temp)
    {
        (*same)+=(long long)temp->count;
        temp->count++;
    }
    else
    {
        insert(id);
    }
}

void extract(int id,long long* same)
{
    int hash=hash_func(id);
    node* temp=hashtable[hash];
    node* prev=NULL;
    while(temp)
    {
        if(temp->id==id)
        {
            temp->count--;
            (*same)-=(long long)temp->count;
            if(temp->count==0)
            {
                if(prev==NULL)
                {
                    hashtable[hash]=(node*)temp->next;
                    free(temp);
                }
                else
                {
                    prev->next=temp->next;
                    free(temp);
                }
            }
            break;
        }
        prev=temp;
        temp=(node*)temp->next;
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

long long countGood(int* nums, int numsSize, int k)
{
    int l,r;
    long long ans=0,same=0;
    initialize();
    for(l=0,r=0;l<numsSize;l++)
    {
        while(same<k&&r<numsSize)
        {
            update(nums[r],&same);
            r++;
        }
        if(same>=k)
        {
            ans+=(long long)(numsSize-r+1);
        }
        extract(nums[l],&same);
    }
    clear();
    return ans;
}
