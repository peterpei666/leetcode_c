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

#define N 300

typedef struct
{
    unsigned long long list[N/8+1];
} bitset;

static inline void reset_all(bitset* a)
{
    memset(a->list,0,N);
}

static inline void set(bitset* a,int i)
{
    a->list[i>>6]|=1ULL<<(i&63);
}

static inline bool test(const bitset* a,int i)
{
    return (a->list[i>>6]&(1ULL<<(i&63)))!=0;
}

bool dfs(char* s,int n,int i,bitset* memo,bitset* valid)
{
    if(test(valid,i))
    {
        return test(memo,i);
    }
    if(i==n)
    {
        return true;
    }
    set(valid,i);
    char* temp=(char*)malloc(n+1);
    for(int j=i+1;j<=n;j++)
    {
        temp[j-i-1]=s[j-1];
        temp[j-i]='\0';
        if(count(temp)&&dfs(s,n,j,memo,valid))
        {
            free(temp);
            set(memo,i);
            return true;
        }
    }
    free(temp);
    return false;
}

bool wordBreak(char* s, char** wordDict,int m)
{
    initialize();
    for(int i=0;i<m;i++)
    {
        insert(wordDict[i]);
    }
    bitset memo;
    bitset valid;
    reset_all(&memo);
    reset_all(&valid);
    int n=(int)strlen(s);
    return dfs(s,n,0,&memo,&valid);
}
