#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void invert(struct TreeNode* node)
{
    struct TreeNode* temp=node->left;
    node->left=node->right;
    node->right=temp;
    if(node->left)
    {
        invert(node->left);
    }
    if(node->right)
    {
        invert(node->right);
    }
}

struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    invert(root);
    return root;
}
