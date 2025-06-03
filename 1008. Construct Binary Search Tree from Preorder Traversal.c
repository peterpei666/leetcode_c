#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* create(int val)
{
    struct TreeNode* newnode=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->val=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void construct(struct TreeNode* node,int val)
{
    if(val<node->val)
    {
        if(node->left)
        {
            construct(node->left,val);
            return;
        }
        else
        {
            node->left=create(val);
            return;
        }
    }
    else
    {
        if(node->right)
        {
            construct(node->right,val);
            return;
        }
        else
        {
            node->right=create(val);
            return;
        }
    }
}

struct TreeNode* bstFromPreorder(int* preorder, int n)
{
    int i;
    struct TreeNode* root=create(preorder[0]);
    for(i=1;i<n;i++)
    {
        construct(root,preorder[i]);
    }
    return root;
}
