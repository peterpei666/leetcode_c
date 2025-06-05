#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10083

typedef struct node
{
    char str[12];
    int m;
    int n;
    struct node* next;
} node;

node* hashtable[M];
int count;

void initialize(void)
{
    int i;
    count=0;
    memset(hashtable,0,sizeof(hashtable));
}

inline int hash_func(char* s)
{
    int hash=0;
    while(*s)
    {
        hash=hash*131+(*s++);
        hash%=M;
    }
    return hash;
}

node* create(char* s,int m)
{
    node* newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->str,s);
    newnode->m=m;
    newnode->n=1;
    newnode->next=NULL;
    return newnode;
}

node* find(char* s)
{
    int hash=hash_func(s);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(strcmp(temp->str,s)==0)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

void insert(char* s,int m)
{
    int hash=hash_func(s);
    node* newnode=create(s,m);
    newnode->next=hashtable[hash];
    hashtable[hash]=newnode;
}

void clear(void)
{
    int i;
    node* temp;
    node* prev;
    for(i=0;i<M;i++)
    {
        temp=hashtable[i];
        while(temp)
        {
            prev=temp;
            temp=temp->next;
            free(prev);
        }
    }
}

char* findCommonResponse(char*** responses, int responsesSize, int* responsesColSize)
{
    int i,j;
    node* temp;
    char* ret=(char*)malloc(sizeof(char)*20);
    int cnt;
    initialize();
    for(i=0;i<responsesSize;i++)
    {
        for(j=0;j<responsesColSize[i];j++)
        {
            temp=find(responses[i][j]);
            if(temp&&temp->m!=i+1)
            {
                temp->m=i+1;
                temp->n++;
            }
            if(temp==NULL)
            {
                insert(responses[i][j],i+1);
            }
        }
    }
    cnt=0;
    ret[0]='\0';
    for(i=0;i<M;i++)
    {
        temp=hashtable[i];
        while(temp)
        {
            if(temp->n>cnt)
            {
                cnt=temp->n;
                strcpy(ret,temp->str);
            }
            else if(temp->n==cnt&&strcmp(temp->str,ret)<0)
            {
                strcpy(ret,temp->str);
            }
            temp=temp->next;
        }
    }
    clear();
    return ret;
}
