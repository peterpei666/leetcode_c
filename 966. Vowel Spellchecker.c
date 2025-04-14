#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10083

void lower(char* s,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            s[i]=s[i]-'A'+'a';
        }
    }
}

void vowel(char* s,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            s[i]='*';
        }
    }
}

typedef struct
{
    char key[10];
    char word[10];
    int len;
    struct node* next;
} node;

node* hashtable[MAX];

void initialize(void)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        hashtable[i]=NULL;
    }
}

node* create(char* key,char* word,int len)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->len=len;
    strcpy(newnode->key,key);
    strcpy(newnode->word,word);
    newnode->next=NULL;
    return newnode;
}

int hash_func(char* key,int len)
{
    int i,hash=0;
    for(i=0;i<len;i++)
    {
        hash+=key[i];
        hash*=97;
        hash%=MAX;
    }
    return hash;
}

int find(char* key,int len)
{
    int hash=hash_func(key,len);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->len==len&&strcmp(temp->key,key)==0)
        {
            return 1;
        }
        temp=(node*)temp->next;
    }
    return 0;
}

void insert(char* key,char* word,int len)
{
    node* newnode=create(key,word,len);
    int hash=hash_func(key,len);
    newnode->next=(struct node*)hashtable[hash];
    hashtable[hash]=newnode;
}

void update(char* word)
{
    char* key=strdup(word);
    int len=(int)strlen(word);
    insert(key,word,len);
    lower(key,len);
    if(find(key,len)==0)
    {
        insert(key,word,len);
    }
    vowel(key,len);
    if(find(key,len)==0)
    {
        insert(key,word,len);
    }
    free(key);
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

char* query(char* key)
{
    int len=(int)strlen(key);
    int hash;
    node* temp;
    node* last=NULL;
    hash=hash_func(key,len);
    temp=hashtable[hash];
    while(temp)
    {
        if(temp->len==len&&strcmp(temp->key,key)==0)
        {
            return temp->word;
        }
        temp=(node*)temp->next;
    }
    lower(key,len);
    hash=hash_func(key,len);
    temp=hashtable[hash];
    while(temp)
    {
        if(temp->len==len&&strcmp(temp->key,key)==0)
        {
            last=temp;
        }
        temp=(node*)temp->next;
    }
    if(last)
    {
        return last->word;
    }
    vowel(key,len);
    hash=hash_func(key,len);
    temp=hashtable[hash];
    while(temp)
    {
        if(temp->len==len&&strcmp(temp->key,key)==0)
        {
            return temp->word;
        }
        temp=(node*)temp->next;
    }
    return NULL;
}

char** spellchecker(char** wordlist, int wordlistSize, char** queries, int queriesSize, int* returnSize)
{
    int i;
    char* t;
    initialize();
    for(i=0;i<wordlistSize;i++)
    {
        update(wordlist[i]);
    }
    char** result=(char**)malloc(sizeof(char*)*queriesSize);
    for(i=0;i<queriesSize;i++)
    {
        t=query(queries[i]);
        if(t)
        {
            result[i]=strdup(t);
        }
        else
        {
            result[i]=(char*)malloc(sizeof(char));
            result[i][0]='\0';
        }
    }
    *returnSize=queriesSize;
    clear();
    return result;
}
