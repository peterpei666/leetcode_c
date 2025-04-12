#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10083

typedef struct
{
    int letter[26];
    struct node* next;
} node;

node* hashtable[MAX];

int hash_func(char* word)
{
    int hash=0,i,len;
    len=(int)strlen(word);
    for(i=0;i<len;i++)
    {
        hash+=word[i];
    }
    return hash*97%MAX;
}

void initialize(void)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        hashtable[i]=NULL;
    }
}

node* create(char* word)
{
    node* newnode=(node*)malloc(sizeof(node));
    int i,len;
    len=(int)strlen(word);
    for(i=0;i<26;i++)
    {
        newnode->letter[i]=0;
    }
    for(i=0;i<len;i++)
    {
        newnode->letter[word[i]-'a']++;
    }
    newnode->next=NULL;
    return newnode;
}

node* find(char* word)
{
    int f,hash,i,len;
    int letter[26];
    node* temp;
    len=(int)strlen(word);
    for(i=0;i<26;i++)
    {
        letter[i]=0;
    }
    for(i=0;i<len;i++)
    {
        letter[word[i]-'a']++;
    }
    hash=hash_func(word);
    temp=hashtable[hash];
    while(temp)
    {
        f=1;
        for(i=0;i<26;i++)
        {
            if(letter[i]!=temp->letter[i])
            {
                f=0;
                break;
            }
        }
        if(f)
        {
            return temp;
        }
        temp=(node*)temp->next;
    }
    return NULL;
}

void insert(char* word)
{
    int hash=hash_func(word);
    node* newnode=create(word);
    newnode->next=(struct node*)hashtable[hash];
    hashtable[hash]=newnode;
}

void clear(void)
{
    int i;
    node* prev;
    node* temp;
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

char** removeAnagrams(char** words, int wordsSize, int* returnSize)
{
    int i,j;
    node* temp=NULL;
    initialize();
    for(i=0,j=0;i<wordsSize;i++)
    {
        temp=find(words[i]);
        if(temp==NULL)
        {
            insert(words[i]);
            words[j]=words[i];
            j++;
        }
    }
    clear();
    *returnSize=j;
    return words;
}
