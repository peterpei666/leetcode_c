#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MF 100000
#define M 100087

typedef struct
{
    int key;
    int freq;
    struct node* next;
} node;

typedef struct
{
    int val;
    struct snode* next;
} snode;

typedef struct
{
    node** freqmap;
    snode* group[MF];
    int max;
} FreqStack;

int hash_func(int key)
{
    return abs(key)%M;
}

node* find(node** table,int key)
{
    int hash=hash_func(key);
    node* temp=table[hash];
    while(temp)
    {
        if(temp->key==key)
        {
            return temp;
        }
        temp=(node*)temp->next;
    }
    return NULL;
}

void update(node** table,int key,int d)
{
    int hash=hash_func(key);
    node* temp=table[hash];
    node* new;
    while(temp)
    {
        if(temp->key==key)
        {
            temp->freq+=d;
            if(temp->freq==0)
            {
                new=(node*)temp->next;
                free(temp);
                table[hash]=new;
            }
            return;
        }
        temp=(node*)temp->next;
    }
    node* newnode=(node*)malloc(sizeof(node));
    newnode->key=key;
    newnode->freq=d;
    newnode->next=(struct node*)table[hash];
    table[hash]=newnode;
}


FreqStack* freqStackCreate(void)
{
    int i;
    FreqStack* obj=(FreqStack*)malloc(sizeof(FreqStack));
    obj->freqmap=(node**)malloc(sizeof(node*)*M);
    for(i=0;i<M;i++)
    {
        obj->freqmap[i]=NULL;
    }
    for(i=0;i<MF;i++)
    {
        obj->group[i]=NULL;
    }
    obj->max=0;
    return obj;
}

void freqStackPush(FreqStack* obj, int val)
{
    node* temp=find(obj->freqmap,val);
    int nf=(temp?temp->freq:0)+1;
    update(obj->freqmap,val,1);
    if(nf>obj->max)
    {
        obj->max=nf;
    }
    snode* newnode=(snode*)malloc(sizeof(snode));
    newnode->val=val;
    newnode->next=(struct snode*)obj->group[nf];
    obj->group[nf]=newnode;
}

int freqStackPop(FreqStack* obj)
{
    if(obj->max==0)
    {
        return -1;
    }
    snode* temp=obj->group[obj->max];
    if(temp==NULL)
    {
        return -1;
    }
    int val=temp->val;
    obj->group[obj->max]=(snode*)temp->next;
    free(temp);
    update(obj->freqmap,val,-1);
    if(obj->group[obj->max]==NULL)
    {
        obj->max--;
    }
    return val;
}

void freqStackFree(FreqStack* obj)
{
    int i;
    node* temp1;
    node* prev1;
    snode* temp2;
    snode* prev2;
    for(i=0;i<M;i++)
    {
        temp1=obj->freqmap[i];
        while(temp1)
        {
            prev1=temp1;
            temp1=(node*)temp1->next;
            free(prev1);
        }
    }
    for(i=0;i<MF;i++)
    {
        temp2=obj->group[i];
        while(temp2)
        {
            prev2=temp2;
            temp2=(snode*)temp2->next;
            free(prev2);
        }
    }
    free(obj);
}
