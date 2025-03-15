#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int day;
    int value;
    struct node* next;
} node;

node* create(int day,int value)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->day=day;
    newnode->value=value;
    newnode->next=NULL;
    return newnode;
}

node q;
node* tail;

void calculate(int* list,node* start,int end)
{
    node* temp=start;
    node* prev=NULL;
    while(temp)
    {
        list[temp->day]=end-temp->day;
        prev=temp;
        temp=(node*)temp->next;
        free(prev);
    }
}

void insert(int* list,int day,int value)
{
    node* newnode=create(day,value);
    node* temp;
    node* prev;
    if(q.next==NULL)
    {
        q.next=(struct node*)newnode;
        tail=newnode;
        return;
    }
    if(value<=tail->value)
    {
        tail->next=(struct node*)newnode;
        tail=newnode;
        return;
    }
    temp=(node*)q.next;
    prev=NULL;
    while(temp&&temp->value>=value)
    {
        prev=temp;
        temp=(node*)temp->next;
    }
    if(prev)
    {
        prev->next=(struct node*)newnode;
        tail=newnode;
        calculate(list,temp,day);
    }
    else
    {
        calculate(list,(node*)q.next,day);
        q.next=(struct node*)newnode;
        tail=newnode;
    }
}

void clear(node* start)
{
    node* temp=start;
    node* prev=NULL;
    while(temp)
    {
        prev=temp;
        temp=(node*)temp->next;
        free(prev);
    }
}

int* dailyTemperatures(int* temperatures,int temperaturesSize,int* returnSize)
{
    int i,j,temp=0;
    *returnSize=temperaturesSize;
    int* list=(int*)calloc(temperaturesSize,sizeof(int));
    q.next=NULL;
    tail=NULL;
    for(i=0;i<temperaturesSize;i++)
    {
        insert(list,i,temperatures[i]);
    }
    clear((node*)q.next);
    return list;
}
