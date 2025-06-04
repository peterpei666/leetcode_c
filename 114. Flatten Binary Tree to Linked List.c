#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* tail;

void construct(struct TreeNode* node)
{
    tail->left=NULL;
    tail->right=node;
    tail=node;
    struct TreeNode* l=node->left;
    struct TreeNode* r=node->right;
    if(l)
    {
        construct(l);
    }
    if(r)
    {
        construct(r);
    }
}

void flatten(struct TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    struct TreeNode dummy;
    tail=&dummy;
    construct(root);
}
