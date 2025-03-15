#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct queuenode
{
    int val;
    int depth;
    struct TreeNode* node;
    struct queuenode* next;
};

struct queuenode q;
struct queuenode* tail=NULL;

struct queuenode* create(struct TreeNode* node,int depth)
{
    struct queuenode* newnode=(struct queuenode*)malloc(sizeof(struct queuenode));
    newnode->val=node->val;
    newnode->node=node;
    newnode->depth=depth;
    newnode->next=NULL;
    return newnode;
}

void insert(struct TreeNode* node,int depth)
{
    struct queuenode* newnode=create(node,depth);
    if(q.next==NULL)
    {
        q.next=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}

void pop(void)
{
    struct queuenode* temp=q.next;
    q.next=temp->next;
    free(temp);
}

void bfs(int*** list,int* returnSize,int** returnColumnSizes)
{
    int size=*returnSize,depth;
    while(q.next)
    {
        depth=q.next->depth;
        if(depth>=size)
        {
            size=depth+1;
            *returnSize=size;
            *returnColumnSizes=(int*)realloc(*returnColumnSizes,size*sizeof(int));
            *list=(int**)realloc(*list,size*sizeof(int*));
            (*list)[depth]=(int*)malloc(sizeof(int));
            (*returnColumnSizes)[depth]=0;
        }
        (*list)[depth]=(int*)realloc((*list)[depth],((*returnColumnSizes)[depth]+1)*sizeof(int));
        (*list)[depth][(*returnColumnSizes)[depth]]=q.next->val;
        (*returnColumnSizes)[depth]++;
        if(q.next->node->left)
        {
            insert(q.next->node->left,depth+1);
        }
        if(q.next->node->right)
        {
            insert(q.next->node->right,depth+1);
        }
        pop();
    }
}

int** levelOrder(struct TreeNode* root,int* returnSize,int** returnColumnSizes)
{
    q.next=NULL;
    tail=NULL;
    if(root==NULL)
    {
        *returnSize=0;
        return NULL;
    }
    int** list=(int**)malloc(sizeof(int*));
    *returnSize=0;
    *returnColumnSizes=(int*)malloc(sizeof(int));
    (*returnColumnSizes)[0]=0;
    insert(root,0);
    bfs(&list,returnSize,returnColumnSizes);
    return list;
}
