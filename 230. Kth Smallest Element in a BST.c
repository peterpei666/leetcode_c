#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int i,ans;

void inorder(struct TreeNode* node,int k)
{
    if(i>=k)
    {
        return;
    }
    if(node->left)
    {
        inorder(node->left,k);
    }
    if(i>k)
    {
        return;
    }
    if(i==k)
    {
        ans=node->val;
    }
    i++;
    if(node->right)
    {
        inorder(node->right,k);
    }
}

int kthSmallest(struct TreeNode* root, int k)
{
    ans=0;
    i=0;
    inorder(root,k);
    return ans;
}
