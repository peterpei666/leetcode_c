#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct queue
{
    struct TreeNode** list;
    int head;
    int sz;
    int capacity;
} queue;

static inline queue* initialize(void)
{
    queue* q=(queue*)malloc(sizeof(queue));
    q->list=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*128);
    q->head=0;
    q->sz=0;
    q->capacity=128;
    return q;
}

static inline void reallocation(queue* q)
{
    int size=q->sz-q->head;
    q->capacity*=2;
    struct TreeNode** new=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*q->capacity);
    memcpy(new,q->list+q->head,sizeof(struct TreeNode*)*size);
    free(q->list);
    q->sz-=q->head;
    q->head=0;
    q->list=new;
}

static inline void push(queue* q,struct TreeNode* node)
{
    if(q->sz>=q->capacity)
    {
        reallocation(q);
    }
    q->list[q->sz]=node;
    q->sz++;
}

static inline struct TreeNode* front(queue* q)
{
    return q->list[q->head];
}

static inline void pop(queue* q)
{
    q->head++;
}
 
static inline bool empty(queue* q)
{
    return q->head==q->sz;
}

static inline void clear(queue* q)
{
    free(q->list);
    free(q);
}

static inline struct TreeNode* create(int val)
{
    struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}

static void readInt(char* data,int n,int* i,int* ans)
{
    *ans=0;
    int neg=0;
    if(data[*i]=='-')
    {
        neg=1;
        (*i)++;
    }
    while(*i<n&&data[*i]!=',')
    {
        *ans=(*ans)*10+(data[*i]-'0');
        (*i)++;
    }
    if(neg)
    {
        *ans=-(*ans);
    }
    if(*i<n&&data[*i]==',')
    {
        (*i)++;
    }
}

char* serialize(struct TreeNode* root)
{
    int capacity = 1024;
    char* s=(char*)malloc(capacity);
    s[0]='\0';
    int len=0;
    if (!root)
    {
        strcpy(s,"null");
        return s;
    }
    queue* q=initialize();
    push(q,root);
    char temp[10];
    while(!empty(q))
    {
        struct TreeNode* node=front(q);
        pop(q);
        if(node)
        {
            sprintf(temp,"%d,",node->val);
            int sz=len+(int)strlen(temp)+1;
            if(sz>capacity)
            {
                capacity*=2;
                s=(char*)realloc(s,capacity);
            }
            strcpy(s+len,temp);
            len+=strlen(temp);
            push(q,node->left);
            push(q,node->right);
        }
        else
        {
            const char* nullstr="null,";
            int sz=len+5+1;
            if(sz>capacity)
            {
                capacity*=2;
                s=(char*)realloc(s,capacity);
            }
            strcpy(s+len,nullstr);
            len+=5;
        }
    }
    if(len>0&&s[len-1]==',')
    {
        s[len-1]='\0';
    }
    clear(q);
    return s;
}

struct TreeNode* deserialize(char* data)
{
    if(strcmp(data,"null")==0)
    {
        return NULL;
    }
    int n=(int)strlen(data);
    int i=0;
    int val;
    readInt(data,n,&i,&val);
    struct TreeNode* root=create(val);
    queue* q=initialize();
    push(q,root);
    while(!empty(q))
    {
        struct TreeNode* node=front(q);
        pop(q);
        if(i<n&&data[i]=='n')
        {
            i+=4;
            if(i<n&&data[i]==',')
            {
                i++;
            }
            node->left=NULL;
        }
        else if(i<n)
        {
            readInt(data,n,&i,&val);
            node->left=create(val);
            push(q,node->left);
        }
        if(i<n&&data[i]=='n')
        {
            i+=4;
            if(i<n&&data[i]==',')
            {
                i++;
            }
            node->right=NULL;
        }
        else if(i<n)
        {
            readInt(data,n,&i,&val);
            node->right=create(val);
            push(q,node->right);
        }
    }
    clear(q);
    return root;
}
