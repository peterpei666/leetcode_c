#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define M 10083
    
typedef struct
{
    char* s;
    struct node* next;
} node;
    
node* hashtable[M];
    
static inline void initialize(void)
{
    int i;
    memset(hashtable,0,sizeof(hashtable));
}
    
static inline int hash_func(char* s)
{
    int hash=0,i=0;
    while(s[i]!='\0') hash=(hash*97+s[i++])%M;
    return hash;
}
    
static inline node* create(char* s)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->s=s;
    newnode->next=NULL;
    return newnode;
}
    
static inline bool count(char* s)
{
    int hash=hash_func(s);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(strcmp(temp->s,s)==0)
        {
            return true;
        }
        temp=(node*)temp->next;
    }
    return false;
}
    
static inline void insert(char* s)
{
    int hash=hash_func(s);
    node* newnode=create(s);
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

void dfs(char* s,int n,int i,char* path,char*** ans,int* sz,int* capacity)
{
    if(i==n)
    {
        if(*sz>=*capacity)
        {
            (*capacity)*=2;
            (*ans)=(char**)realloc(*ans,sizeof(char*)*(*capacity));
        }
        (*ans)[*sz]=strdup(path);
        (*sz)++;
    }
    char* temp=(char*)malloc(2*n+1);
    for(int j=i+1;j<=n;j++)
    {
        temp[j-i-1]=s[j-1];
        temp[j-i]='\0';
        if(count(temp))
        {
            int m=(int)strlen(path);
            if(m>0)
            {
                strcat(path," ");
            }
            strcat(path,temp);
            dfs(s,n,j,path,ans,sz,capacity);
            path[m]='\0';
        }
    }
    free(temp);
}

char** wordBreak(char* s, char** wordDict, int m, int* returnSize)
{
    initialize();
    for(int i=0;i<m;i++)
    {
        insert(wordDict[i]);
    }
    int n=(int)strlen(s);
    char** ans=(char**)malloc(sizeof(char*)*10);
    char* path=(char*)malloc(2*n+1);
    int sz=0,capacity=10;
    path[0]='\0';
    dfs(s,n,0,path,&ans,&sz,&capacity);
    free(path);
    clear();
    *returnSize=sz;
    return ans;
}
