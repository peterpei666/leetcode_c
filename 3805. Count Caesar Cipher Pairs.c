#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10083

typedef struct node
{
    char* m;
    int n;
    struct node* next;
} node;

node* hashtable[M];
int count;

static inline void initialize(void)
{
    count=0;
    memset(hashtable,0,sizeof(hashtable));
}

static inline int hash_func(char* s)
{
    int hash=0,i=0;
    while(s[i]!='\0') hash=(hash*97+s[i++])%M;
    return hash;
}

static inline node* create(char* m, int n)
{
     node* newnode=(node*)malloc(sizeof(node));
     newnode->m=strdup(m);
     newnode->n=n;
     newnode->next=NULL;
     return newnode;
}

static inline node* find(char* m)
{
    int hash=hash_func(m);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(strcmp(temp->m,m) == 0)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

static inline void insert(char* m, int n)
{
    int hash=hash_func(m);
    node* newnode=create(m,n);
    newnode->next=hashtable[hash];
    hashtable[hash]=newnode;
}

static inline void clear(void)
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
            free(prev->m);
            free(prev);
        }
    }
}

long long countPairs(char** words, int n)
{
    int m = (int)strlen(words[0]);
    char key[m + 1];
    key[m] = '\0';
    initialize();
    for (int i = 0; i < n; i++)
    {
        int a = words[i][0] - 'a';
        for (int j = 0; j < m; j++)
        {
            key[j] = (words[i][j] - 'a' - a + 26) % 26 + 'a';
        }
        node* temp = find(key);
        if (temp)
        {
            temp->n++;
        }
        else
        {
            insert(key, 1);
        }
    }
    long long ans = 0;
    for (int i = 0; i < M; i++)
    {
        node* temp = hashtable[i];
        while (temp)
        {
            ans += 1LL * temp->n * (temp->n - 1);
            temp = temp->next;
        }
    }
    clear();
    return ans >> 1;
}
