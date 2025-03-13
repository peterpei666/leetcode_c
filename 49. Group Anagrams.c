#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define H 10083

typedef struct
{
    char* key;
    char** list;
    int size;
    int capacity;
    struct node* next;
} node;

int compare(const void* p1,const void* p2)
{
    char a=*(char*)p1;
    char b=*(char*)p2;
    return (int)(a-b);
}

int hash_func(char* word)
{
    int hash=0,i,len=(int)strlen(word);
    for(i=0;i<len;i++)
    {
        hash+=*(word+i);
        hash<<=3;
        hash%=H;
    }
    return hash;
}

node* table[H];

node* create(void)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->key=NULL;
    newnode->capacity=10;
    newnode->list=(char**)malloc(sizeof(char*)*newnode->capacity);
    newnode->size=0;
    newnode->next=NULL;
    return newnode;
}

void insert(char* word)
{
    char* temp=strdup(word);
    qsort(temp,strlen(word),sizeof(char),compare);
    int hash=hash_func(temp);
    if(table[hash]==NULL)
    {
        node* newnode=create();
        newnode->key=temp;
        newnode->size++;
        newnode->list[0]=word;
        table[hash]=newnode;
    }
    else
    {
        node* t=table[hash];
        while(t->next&&strcmp(t->key,temp)!=0)
        {
            t=(node*)t->next;
        }
        if(strcmp(t->key,temp)==0)
        {
            if(t->size>=t->capacity-2)
            {
                t->capacity+=10;
                t->list=(char**)realloc(t->list,t->capacity*sizeof(char*));
            }
            t->list[t->size]=word;
            t->size++;
            free(temp);
        }
        else
        {
            node* newnode=create();
            newnode->key=temp;
            newnode->size++;
            newnode->list[0]=word;
            t->next=(struct node*)newnode;
        }
    }
}

void clear(void)
{
    int i;
    node* temp;
    node* prev;
    for(i=0;i<H;i++)
    {
        if(table[i])
        {
            temp=table[i];
            while(temp->next)
            {
                prev=temp;
                temp=(node*)temp->next;
                free(prev);
            }
            free(temp);
            table[i]=NULL;
        }
    }
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    if(strs==NULL)
    {
        *returnSize=0;
        return NULL;
    }
    int i=0,count=0,capacity=10;
    node* temp;
    char*** ans=(char***)malloc(sizeof(char**)*capacity);
    *returnColumnSizes=(int*)malloc(sizeof(int)*capacity);
    clear();
    for(i=0;i<strsSize;i++)
    {
        insert(strs[i]);
    }
    for(i=0;i<H;i++)
    {
        if(table[i])
        {
            temp=table[i];
            while(temp)
            {
                if(count>=capacity-2)
                {
                    capacity+=10;
                    ans=(char***)realloc(ans,sizeof(char**)*capacity);
                    *returnColumnSizes=(int*)realloc(*returnColumnSizes,sizeof(int)*capacity);
                }
                ans[count]=temp->list;
                (*returnColumnSizes)[count]=temp->size;
                temp=(node*)temp->next;
                count++;
            }
        }
    }
    *returnSize=count;
    return ans;
}
