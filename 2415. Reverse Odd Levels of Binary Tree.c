#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void reverse(struct TreeNode* l,struct TreeNode* r,bool odd)
{
    if(l==NULL||r==NULL)
    {
        return;
    }
    if(odd)
    {
        int temp=l->val;
        l->val=r->val;
        r->val=temp;
    }
    reverse(l->left,r->right,!odd);
    reverse(l->right,r->left,!odd);
}

struct TreeNode* reverseOddLevels(struct TreeNode* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    reverse(root->left,root->right,true);
    return root;
}
