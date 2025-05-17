#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define M 100083

typedef struct
{
    int x;
    int y;
    struct node* next;
} node;

node* hashtable[M];

void initialize(void)
{
    int i;
    for(i=0;i<M;i++)
    {
        hashtable[i]=NULL;
    }
}

inline int hash_func(int x,int y)
{
    return ((x*y)%M*(x^y))%M;
}

node* create(int x,int y)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->x=x;
    newnode->y=y;
    newnode->next=NULL;
    return newnode;
}

node* find(int x,int y)
{
    int hash=hash_func(x,y);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->x==x&&temp->y==y)
        {
            return temp;
        }
        temp=(node*)temp->next;
    }
    return NULL;
}

void insert(int x,int y)
{
    int hash=hash_func(x,y);
    node* newnode=create(x,y);
    newnode->next=(struct node*)hashtable[hash];
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
            temp=(node*)temp->next;
            free(prev);
        }
    }
}

bool isPathCrossing(char* path)
{
    int i,len;
    int x=0,y=0;
    len=(int)strlen(path);
    initialize();
    insert(0,0);
    for(i=0;i<len;i++)
    {
        switch(path[i])
        {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;;
            case 'E':
                x++;
                break;;
            case 'W':
                x--;
                break;;
        }
        if(find(x,y))
        {
            clear();
            return true;
        }
        insert(x,y);
    }
    clear();
    return false;
}
