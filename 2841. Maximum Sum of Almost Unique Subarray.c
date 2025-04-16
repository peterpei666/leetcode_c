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

void update(int id,int* count)
{
    node* temp=find(id);
    if(temp)
    {
        temp->count++;
    }
    else
    {
        insert(id);
        (*count)++;
    }
}

void extract(int id,int* count)
{
    int hash=hash_func(id);
    node* temp=hashtable[hash];
    node* prev=NULL;
    while(temp)
    {
        if(temp->id==id)
        {
            temp->count--;
            if(temp->count==0)
            {
                (*count)--;
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

inline long long maxi(long long a,long long b)
{
    return a>b?a:b;
}

long long maxSum(int* nums, int numsSize, int m, int k)
{
    int count=0,i;
    long long sum=0,ret=0;
    initialize();
    for(i=0;i<k;i++)
    {
        sum+=(long long)nums[i];
        update(nums[i],&count);
    }
    if(count>=m)
    {
        ret=maxi(ret,sum);
    }
    for(i=k;i<numsSize;i++)
    {
        sum+=(long long)nums[i];
        update(nums[i],&count);
        sum-=(long long)nums[i-k];
        extract(nums[i-k],&count);
        if(count>=m)
        {
            ret=maxi(ret,sum);
        }
    }
    clear();
    return ret;
}
