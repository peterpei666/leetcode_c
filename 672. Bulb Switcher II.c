#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 1083

typedef struct
{
    int m;
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

inline int hash_func(int m)
{
    return m*97%M;
}

node* create(int m)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->m=m;
    newnode->next=NULL;
    return newnode;
}

bool find(int m)
{
    int hash=hash_func(m);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->m==m)
        {
            return true;
        }
        temp=(node*)temp->next;
    }
    return false;
}

void insert(int m)
{
    int hash=hash_func(m);
    node* newnode=create(m);
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

inline int min(int a,int b)
{
    return a<b?a:b;
}

int flipLights(int n, int presses)
{
    int mask,b1,b2,b3,b4;
    int state,total,l,i;
    int cnt=0;
    initialize();
    for(int mask=0;mask<16;mask++)
    {
        b1=(mask>>0)&1;
        b2=(mask>>1)&1;
        b3=(mask>>2)&1;
        b4=(mask>>3)&1;
        total=b1+b2+b3+b4;
        if(total%2!=presses%2||total>presses)
        {
            continue;
        }
        state=0;
        for(i=0;i<min(n,3);i++)
        {
            l=1;
            if(b1)
            {
                l^=1;
            }
            if(b2&&i%2==1)
            {
                l^=1;
            }
            if(b3&&i%2==0)
            {
                l^=1;
            }
            if(b4&&i%3==0)
            {
                l^=1;
            }
            state<<=1;
            state+=l;
        }
        if(find(state)==false)
        {
            insert(state);
            cnt++;
        }
    }
    clear();
    return cnt;
}
