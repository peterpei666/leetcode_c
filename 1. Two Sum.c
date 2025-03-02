#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    int id;
    struct node* next;
} node;

node* hash_table[10000]={NULL};

node* create(int data,int id)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->id=id;
    newnode->next=NULL;
    return newnode;
}

void clear(void)
{
    int i;
    for(i=0;i<10000;i++)
    {
        hash_table[i]=NULL;
    }
}

int hash_func(int data)
{
    int hash;
    hash=data%10000+10000;
    return hash%10000;
}

void insert(int data,int id)
{
    int hash=hash_func(data);
    node* temp=hash_table[hash];
    node* newnode=create(data,id);
    newnode->next=(struct node*)hash_table[hash];
    hash_table[hash]=newnode;
}

int find(int data,int target)
{
    int hash=hash_func(target-data);
    int ans=target-data;
    node* temp=hash_table[hash];
    while(temp)
    {
        if(temp->data==ans)
        {
            return temp->id;
        }
        temp=(node*)temp->next;
    }
    return -1;
}

int* twoSum(int* nums,int numsSize,int target,int* returnSize)
{
    clear();
    int i,ret;
    int* list=(int*)malloc(2*sizeof(int));
    for(i=0;i<numsSize;i++)
    {
        ret=find(nums[i],target);
        if(ret>=0)
        {
            list[0]=ret;
            list[1]=i;
            *returnSize=2;
            return list;
        }
        insert(nums[i],i);
    }
    *returnSize=0;
    return NULL;
}
