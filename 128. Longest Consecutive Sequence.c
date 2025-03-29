#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100083

typedef struct
{
    int l;
    int r;
    int len;
    struct node* next;
} node;

typedef struct
{
    int num;
    struct node1* next;
} node1;

node* hashtable[MAX];
node1* hashtable1[MAX];

int hash_func(int x)
{
    return (x%MAX+MAX)%MAX;
}

node* create(int l,int r)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->l=l;
    newnode->r=r;
    newnode->len=r-l+1;
    newnode->next=NULL;
    return newnode;
}

node1* create1(int num)
{
    node1* newnode=(node1*)malloc(sizeof(node1));
    newnode->num=num;
    newnode->next=NULL;
    return newnode;
}

void insert(int l,int r)
{
    node* newnode;
    int hashl,hashr;
    hashl=hash_func(l);
    hashr=hash_func(r);
    newnode=create(l,r);
    newnode->next=(struct node*)hashtable[hashl];
    hashtable[hashl]=newnode;
    newnode=create(l,r);
    newnode->next=(struct node*)hashtable[hashr];
    hashtable[hashr]=newnode;
}

void insert1(int num)
{
    node1* newnode=create1(num);
    int hash;
    hash=hash_func(num);
    newnode->next=(struct node1*)hashtable1[hash];
    hashtable1[hash]=newnode;
}

void initialize(void)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        hashtable[i]=NULL;
        hashtable1[i]=NULL;
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

void clear1(void)
{
    int i;
    node1* temp;
    node1* prev;
    for(i=0;i<MAX;i++)
    {
        temp=hashtable1[i];
        while(temp)
        {
            prev=temp;
            temp=(node1*)temp->next;
            free(prev);
        }
    }
}

void update(int num,int* max)
{
    int left,right,hashl,hashr,len;
    left=num;
    right=num;
    hashl=hash_func(num-1);
    node* templ=hashtable[hashl];
    while(templ)
    {
        if(templ->r==num-1)
        {
            left=templ->l;
            break;
        }
        templ=(node*)templ->next;
    }
    hashr=hash_func(num+1);
    node* tempr=hashtable[hashr];
    while(tempr)
    {
        if(tempr->l==num+1)
        {
            right=tempr->r;
            break;
        }
        tempr=(node*)tempr->next;
    }
    len=right-left+1;
    if(len>*max)
    {
        *max=len;
    }
    insert(left,right);
}

bool find(int x)
{
    int hash=hash_func(x);
    node1* temp=hashtable1[hash];
    while(temp)
    {
        if(temp->num==x)
        {
            return true;
        }
        temp=(node1*)temp->next;
    }
    return false;
}

int longestConsecutive(int* nums, int numsSize)
{
    int i,max=0;
    initialize();
    for(i=0;i<numsSize;i++)
    {
        if(find(nums[i])==false)
        {
            insert1(nums[i]);
            update(nums[i],&max);
        }
    }
    clear();
    clear1();
    return max;
}
