#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

int capacity,count;

void preorder(struct TreeNode* root,int** list)
{
    if(count>=capacity)
    {
        capacity+=10;
        *list=(int*)realloc(*list,capacity*sizeof(int));
    }
    (*list)[count]=root->val;
    count++;
    if(root->left)
    {
        preorder(root->left,list);
    }
    if(root->right)
    {
        preorder(root->right,list);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    if(root==NULL)
    {
        *returnSize=0;
        return NULL;
    }
    capacity=10;
    count=0;
    int* list=(int*)malloc(capacity*sizeof(int));
    preorder(root,&list);
    *returnSize=count;
    return list;
}
