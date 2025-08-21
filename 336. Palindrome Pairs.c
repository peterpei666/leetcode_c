#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define M 10083
    
typedef struct node
{
    char* s;
    int id;
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
    unsigned long long hash=0;
    int n=(int)strlen(s);
    if(n>0) hash = s[0];
    if(n>1) hash=hash*131+s[n-1];
    if(n>4) hash=hash*131+s[n/2];
    for(int i=0;i<n;i+=3)
    {
        hash=(hash*131+s[i])%M;
    }
    return hash%M;
}
    
static inline node* create(char* s,int id)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->s=strdup(s);
    newnode->id=id;
    return newnode;
}
    
static inline node* find(char* s)
{
    int hash=hash_func(s);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(strcmp(temp->s,s)==0)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
    
static inline void insert(char* s,int id)
{
    int hash=hash_func(s);
    node* newnode=create(s,id);
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
            free(prev->s);
            free(prev);
        }
    }
}

static inline void swap(char* a,char* b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}

static inline void reverse(char s[])
{
    for(int l=0,r=(int)strlen(s)-1;l<r;l++,r--) swap(&s[l],&s[r]);
}

static inline bool is_pal(char s[])
{
    for(int l=0,r=(int)strlen(s)-1;l<r;l++,r--) if(s[l]!=s[r]) return false; return true;
}

int** palindromePairs(char** words, int n, int* returnSize, int** returnColumnSizes)
{
    char temp[400];
    initialize();
    for(int i=0;i<n;i++)
    {
        strcpy(temp,words[i]);
        reverse(temp);
        insert(temp,i);
    }
    int** ans=(int**)malloc(sizeof(int*)*32);
    int sz=0,capacity=32;
    if(find(""))
    {
        int t=find("")->id;
        for(int i=0;i<n;i++)
        {
            if(t==i)
            {
                continue;
            }
            if(is_pal(words[i]))
            {
                if(sz==capacity)
                {
                    capacity*=2;
                    ans=(int**)realloc(ans,sizeof(int*)*capacity);
                }
                ans[sz]=(int*)malloc(sizeof(int)*2);
                ans[sz][0]=i;
                ans[sz][1]=t;
                sz++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        memset(temp,'\0',sizeof(temp));
        int k=0;
        int m=(int)strlen(words[i]);
        for(int j=0;j<m;j++)
        {
            temp[k]=words[i][j];
            k++;
            if(find(temp)&&find(temp)->id!=i&&is_pal(words[i]+j+1))
            {
                if(sz==capacity)
                {
                    capacity*=2;
                    ans=(int**)realloc(ans,sizeof(int*)*capacity);
                }
                ans[sz]=(int*)malloc(sizeof(int)*2);
                ans[sz][0]=i;
                ans[sz][1]=find(temp)->id;
                sz++;
            }
            if(find(words[i]+j+1)&&find(words[i]+j+1)->id!=i&&is_pal(temp))
            {
                if(sz==capacity)
                {
                    capacity*=2;
                    ans=(int**)realloc(ans,sizeof(int*)*capacity);
                }
                ans[sz]=(int*)malloc(sizeof(int)*2);
                ans[sz][0]=find(words[i]+j+1)->id;
                ans[sz][1]=i;
                sz++;
            }
        }
    }
    clear();
    *returnSize=sz;
    (*returnColumnSizes)=(int*)malloc(sizeof(int)*sz);
    for(int i=0;i<sz;i++)
    {
        (*returnColumnSizes)[i]=2;
    }
    return ans;
}
