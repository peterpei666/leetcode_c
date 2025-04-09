#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define M 10083

typedef struct
{
    char* str;
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

int hash_func(char* s)
{
    int len=(int)strlen(s);
    int i,hash=0;
    for(i=0;i<len;i++)
    {
        hash*=31;
        hash+=s[i];
        hash%=M;
    }
    return hash;
}

node* create(char* s)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->next=NULL;
    newnode->str=(char*)malloc(sizeof(char)*(strlen(s)+1));
    strcpy(newnode->str,s);
    return newnode;
}

bool check(char* s)
{
    int hash,f=0;
    node* temp;
    char t[31];
    strcpy(t,s);
    t[strlen(s)-1]='\0';
    hash=hash_func(t);
    temp=hashtable[hash];
    while(temp)
    {
        if(strcmp(t,temp->str)==0)
        {
            f=1;
            break;
        }
        temp=(node*)temp->next;
    }
    if(f)
    {
        if(strlen(t)==1)
        {
            return true;
        }
        else
        {
            return check(t);
        }
    }
    else
    {
        return false;
    }
}

void insert(char* s)
{
    node* newnode=create(s);
    int hash=hash_func(s);
    newnode->next=(struct node*)hashtable[hash];
    hashtable[hash]=newnode;
}

void clear(void)
{
    int i;
    node* prev;
    node* temp;
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

char* longestWord(char** words, int wordsSize)
{
    int i;
    char* max=(char*)malloc(sizeof(char)*31);
    max[0]='\0';
    initialize();
    for(i=0;i<wordsSize;i++)
    {
        insert(words[i]);
    }
    for(i=0;i<wordsSize;i++)
    {
        if(strlen(words[i])==1||check(words[i]))
        {
            if(strlen(words[i])>strlen(max))
            {
                strcpy(max,words[i]);
            }
            else if(strlen(words[i])==strlen(max))
            {
                if(strcmp(max,words[i])>0)
                {
                    strcpy(max,words[i]);
                }
            }
        }
    }
    clear();
    return max;
}

