#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define M 10083
    
typedef struct node
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
    newnode->s=strdup(s);
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
        temp=temp->next;
    }
    return false;
}
    
static inline void insert(char* s)
{
    if(count(s)) return;
    int hash=hash_func(s);
    node* newnode=create(s);
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

void dfs(char* s,int n,int idx,int l,int r,int open,char* temp,int m)
{
    if(idx==n)
    {
        if(l==0&&r==0&&open==0)
        {
            temp[m]='\0';
            insert(temp);
        }
        return;
    }
    switch(s[idx])
    {
        case '(':
            if(l>0)
            {
                dfs(s,n,idx+1,l-1,r,open,temp,m);
            }
            temp[m]=s[idx];
            dfs(s,n,idx+1,l,r,open+1,temp,m+1);
            break;
        case ')':
            if(r>0)
            {
                dfs(s,n,idx+1,l,r-1,open,temp,m);
            }
            if(open>0)
            {
                temp[m]=s[idx];
                dfs(s,n,idx+1,l,r,open-1,temp,m+1);
            }
            break;
        default:
            temp[m]=s[idx];
            dfs(s,n,idx+1,l,r,open,temp,m+1);
            break;
    }
}

char** removeInvalidParentheses(char* s, int* returnSize)
{
    int l=0,r=0;
    int n=(int)strlen(s);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            l++;
        }
        else if(s[i]==')')
        {
            if(l>0)
            {
                l--;
            }
            else
            {
                r++;
            }
        }
    }
    initialize();
    char* temp=(char*)malloc(n+1);
    dfs(s,n,0,l,r,0,temp,0);
    free(temp);
    char** ans=(char**)malloc(sizeof(char*)*16);
    int capacity=16,sz=0;
    for(int i=0;i<M;i++)
    {
        node* temp=hashtable[i];
        while(temp)
        {
            if(sz>=capacity)
            {
                capacity*=2;
                ans=(char**)realloc(ans,sizeof(char*)*capacity);
            }
            ans[sz]=temp->s;
            sz++;
            temp=temp->next;
        }
    }
    *returnSize=sz;
    return ans;
}
