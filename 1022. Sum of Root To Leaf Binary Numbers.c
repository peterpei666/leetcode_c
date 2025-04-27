#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void sum(struct TreeNode* node,int current,int* total)
{
    current<<=1;
    current+=node->val;
    if(node->left==NULL&&node->right==NULL)
    {
        (*total)+=current;
        return;
    }
    if(node->left)
    {
        sum(node->left,current,total);
    }
    if(node->right)
    {
        sum(node->right,current,total);
    }
}

int sumRootToLeaf(struct TreeNode* root)
{
    int total=0;
    sum(root,0,&total);
    return total;
}
