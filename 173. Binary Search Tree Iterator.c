#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct
{
    struct TreeNode** list;
    int sz;
    int capacity;
} stack;

stack* initialize(void)
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->list=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*100);
    s->sz=0;
    s->capacity=100;
    return s;
}

void push(stack* s,struct TreeNode* n)
{
    if(s->sz/100*100+100!=s->capacity)
    {
        s->capacity=s->sz/100*100+100;
        s->list=(struct TreeNode**)realloc(s->list,s->capacity*sizeof(struct TreeNode*));
    }
    s->list[s->sz]=n;
    s->sz++;
}

struct TreeNode* top(stack* s)
{
    if(s->sz==0)
    {
        return NULL;
    }
    else
    {
        return s->list[s->sz-1];
    }
}

void pop(stack* s)
{
    if(s->sz)
    {
        s->sz--;
        if(s->sz/100*100+100!=s->capacity)
        {
            s->capacity=s->sz/100*100+100;
            s->list=(struct TreeNode**)realloc(s->list,s->capacity*sizeof(struct TreeNode*));
        }
    }
}

void clear(stack* s)
{
    free(s->list);
    free(s);
}

typedef struct
{
    stack* s;
    struct TreeNode* p;
} BSTIterator;


BSTIterator* bSTIteratorCreate(struct TreeNode* root)
{
    BSTIterator* obj=(BSTIterator*)malloc(sizeof(BSTIterator));
    obj->p=root;
    obj->s=initialize();
    return obj;
}

int bSTIteratorNext(BSTIterator* obj)
{
    struct TreeNode* temp;
    while(obj->p)
    {
        push(obj->s,obj->p);
        obj->p=obj->p->left;
    }
    temp=top(obj->s);
    obj->p=temp->right;
    pop(obj->s);
    return temp->val;
}

bool bSTIteratorHasNext(BSTIterator* obj)
{
    return !(obj->s->sz==0&&obj->p==NULL);
}

void bSTIteratorFree(BSTIterator* obj)
{
    clear(obj->s);
    free(obj);
}
