#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define M 100083

typedef struct node
{
    long long m;
    int n;
    struct node* next;
} node;

node* hashtable[M];
int count;

void initialize(void)
{
    int i;
    count=0;
    memset(hashtable,0,sizeof(hashtable));
}

inline int hash_func(long long m)
{
    return (m*97%M+M)%M;
}

node* create(long long m,int n)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->m=m;
    newnode->n=n;
    newnode->next=NULL;
    return newnode;
}

node* find(long long m)
{
    int hash=hash_func(m);
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->m==m)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

void insert(long long m,int n)
{
    int hash=hash_func(m);
    node* newnode=create(m,n);
    newnode->next=hashtable[hash];
    hashtable[hash]=newnode;
}

void erase(long long m)
{
    int hash=hash_func(m);
    node* prev=NULL;
    node* temp=hashtable[hash];
    while(temp)
    {
        if(temp->m==m)
        {
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL)
    {
        hashtable[hash]=temp->next;
        free(temp);
    }
    else
    {
        prev->next=temp->next;
        free(temp);
    }
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

int dfs(struct TreeNode* n,long long cur,int target)
{
    if(n==NULL)
    {
        return 0;
    }
    int cnt=0;
    node* temp=NULL;
    cur+=n->val;
    temp=find(cur-target);
    if(temp)
    {
        cnt+=temp->n;
    }
    temp=find(cur);
    if(temp)
    {
        temp->n++;
        cnt+=dfs(n->left,cur,target);
        cnt+=dfs(n->right,cur,target);
        temp->n--;
    }
    else
    {
        insert(cur,1);
        cnt+=dfs(n->left,cur,target);
        cnt+=dfs(n->right,cur,target);
        erase(cur);
    }
    return cnt;
}

int pathSum(struct TreeNode* root, int targetSum)
{
    initialize();
    insert(0,1);
    int temp=dfs(root,0,targetSum);
    clear();
    return temp;
}
