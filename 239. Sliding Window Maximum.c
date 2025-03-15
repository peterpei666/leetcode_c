#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
} node;

node q={0,NULL};
node* tail=NULL;

void clear(node* p)
{
    node* temp=p;
    node* prev;
    while(temp)
    {
        prev=temp;
        temp=(node*)temp->next;
        free(prev);
    }
}

node* create(int value)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->value=value;
    newnode->next=NULL;
    return newnode;
}

void insert(int value)
{
    node* newnode=create(value);
    node* temp=(node*)q.next;
    node* prev=NULL;
    if(q.next==NULL)
    {
        q.next=(struct node*)newnode;
        tail=newnode;
        return;
    }
    if(tail&&tail->value>=value)
    {
        tail->next=(struct node*)newnode;
        tail=newnode;
        return;
    }
    while(temp&&temp->value>=value)
    {
        prev=temp;
        temp=(node*)temp->next;
    }
    clear(temp);
    if(prev==NULL)
    {
        q.next=(struct node*)newnode;
        tail=newnode;
    }
    else
    {
        prev->next=(struct node*)newnode;
        tail=newnode;
    }
}

void pop(void)
{
    node* temp=(node*)q.next;
    q.next=temp->next;
    free(temp);
}

int* maxSlidingWindow(int* nums,int numsSize,int k,int* returnSize)
{
    int i,size=numsSize-k+1;
    *returnSize=size;
    int* max=(int*)malloc(size*sizeof(int));
    q=(node){0,NULL};
    tail=NULL;
    for(i=0;i<k;i++)
    {
        insert(nums[i]);
    }
    max[0]=((node*)q.next)->value;
    for(i=k;i<numsSize;i++)
    {
        if(nums[i-k]==((node*)q.next)->value)
        {
            pop();
        }
        insert(nums[i]);
        max[i-k+1]=((node*)q.next)->value;
    }
    clear((node*)q.next);
    return max;
}
